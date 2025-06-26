#pragma once

#include <vector>
#include <cmath>
#include <string>
#include <stdexcept>
#include <iostream>
#include <iomanip>

using std::vector;
using std::string;
using std::cout;
using std::setw;
using std::left;

template <typename T>
class HashTable {
    private:
        struct Item {
            string key;
            T data;
        };

        double _maxLoadFactor;

        vector<Item>* _hashArr;
        int _tableSize = 3;
        int _numOfFilledBuckets = 0;
        int _numOfElements = 0;
        int _collisions = 0; // Resets when the hash changes size

    public:
        HashTable(double maxLoadFactor = 0.7) : _maxLoadFactor(maxLoadFactor) {
            _hashArr = new std::vector<Item>[_tableSize];
        };
        ~HashTable() { delete[] _hashArr; }

        bool insert(string key, T data); // Returns false if key already exists
        bool remove(string key, T* data = nullptr); // Returns false if cannot find
        bool search(string key, T* data = nullptr) const; // False if cannot find
        void printInfo() const;
        string traverse(string process(const T& data)) const;

    private: // Private helper methods
        void resizeToNextPrime();
            int nextPrime(int x) const;
            bool isLikelyPrime(unsigned int x) const;
            int powerMod(int base, int exponent, int mod) const;
        unsigned int hash(const string& value) const;
        double loadFactor(int numOfBucketsFilled, int numOfBuckets) const { return static_cast<double>(numOfBucketsFilled) / numOfBuckets;}
        bool find(
            string key,
            typename vector<Item>::iterator* itPtr = nullptr,
            vector<Item>** bucketPtrPtr = nullptr
        ) const;
        bool isStrEql(string value1, string value2) const;
};

// Public methods --------------------------------------------------------------
template <typename T>
bool HashTable<T>::insert(string key, T data) {
    // Check for duplicates
    if (find(key)) return false;

    // Resize if needed
    double newLoadFactor = loadFactor(_numOfFilledBuckets + 1, _tableSize);
    if (newLoadFactor > _maxLoadFactor) resizeToNextPrime();

    // Insert
    int index = hash(key) % _tableSize;
    // Update members
    _numOfElements++;
    if (_hashArr[index].empty())
        _numOfFilledBuckets++;
    else
        _collisions++;

    // Push the item to the end of the vector
    _hashArr[index].push_back({key, data});

    return true;
}

template <typename T>
bool HashTable<T>::remove(string key, T* data) {
    // Find element
    vector<Item>* bucketPtr;
    typename vector<Item>::iterator it;
    if (!find(key, &it, &bucketPtr)) return false;

    // Set data and remove it from the bucket
    if (data) *data = it->data;
    bucketPtr->erase(it);

    // Set member variables
    _numOfElements--;
    if (bucketPtr->empty()) _numOfFilledBuckets--;
    if (bucketPtr->size() == 1) _collisions--; // No longer colliding

    return true;
}

template <typename T>
bool HashTable<T>::search(string key, T* data) const {
    typename vector<Item>::iterator it;
    if (!find(key, &it)) return false;
    if (data) *data = it->data;
    return true;
}

// Finds the bucket and the iterator for that bucket from the _hashArr
template <typename T>
bool HashTable<T>::find(
    string key,
    typename vector<typename HashTable<T>::Item>::iterator* itPtr,
    vector<typename HashTable<T>::Item>** bucketPtrPtr
) const {
    int index = hash(key) % _tableSize;

    for (auto itemIterator = _hashArr[index].begin(); itemIterator != _hashArr[index].end(); itemIterator++) {
        if (isStrEql(itemIterator->key, key)) {
            if (itPtr) *itPtr = itemIterator;
            if (bucketPtrPtr) *bucketPtrPtr = &_hashArr[index];
            return true;
        }
    }

    return false;
}

template <typename T>
void HashTable<T>::printInfo() const {
    cout << left
             << setw(30) << "  Table size: "               << _tableSize          << "\n"
             << setw(30) << "  Number of filled buckets: " << _numOfFilledBuckets << "\n"
             << setw(30) << "  Number of elements: "       << _numOfElements      << "\n"
             << setw(30) << "  Collisions: "               << _collisions         << "\n";
    // For testing purposes. Print hashTable
    /*
    cout << left
             << "  Index   Elements\n";
    for (int i = 0; i < _tableSize; i++) {
        cout << "    " << setw(6) << i;
        for (int j = 0; j < _hashArr[i].size(); j++) {
            cout << _hashArr[i][j].key << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    */
}

// Goes through each element and runs process on it and concatenates the result of the processes into one string
template <typename T>
string HashTable<T>::traverse(string process(const T& data)) const {
    string returnStr = "";
    for (int i = 0; i < _tableSize; i++) {
        if (!_hashArr[i].empty()) {
            for (int j = 0; j < _hashArr[i].size(); j++) {
                returnStr += process(_hashArr[i][j].data);
            }
        }
    }
    return returnStr;
}

// Private helper methods ------------------------------------------------------
template <typename T>
void HashTable<T>::resizeToNextPrime() {
    int newSize = nextPrime(_tableSize * 2);
    vector<Item>* newArray = new vector<Item>[newSize];

    // Reset member variables
    _numOfFilledBuckets = 0;
    _collisions = 0;

    // Move all elements from old array to new one
    for (int i = 0; i < _tableSize; i++) {
        if (!_hashArr[i].empty()) { // If there is a element in the bucket
            for (Item& item : _hashArr[i]) { // For each item in the bucket
                int index = hash(item.key) % newSize;
                // Update members
                if (newArray[index].empty())
                    _numOfFilledBuckets++;
                else
                    _collisions++;
                // Push the item to the end of the vector
                newArray[index].push_back(item);
            }
        }
    }

    // Set the new array
    delete[] _hashArr;
    _hashArr = newArray;
    _tableSize = newSize;
}

template <typename T>
int HashTable<T>::nextPrime(int x) const {
    while (!isLikelyPrime(++x));
    return x;
}

template <typename T>
bool HashTable<T>::isLikelyPrime(unsigned int x) const {
    switch (x) {
        case 0:
        case 1:
            return false;
        case 2:
        case 3:
            return true;
    }
    // Used to speed things up
    const int beginningTests = x > 10 ? 10 : 2;
    for (int i = 2; i < beginningTests; i++) {
        if (x % i == 0) return false;
    }
    // Fermat's little theorem: a - random number between 2 and x
        // If a^(x-1) mod x is not 1, then it's not prime
        // else it is most likely prime, but do more tests to increase probability
    const int tests = 1;
    for (int i = 0; i < tests; i++) {
        int a = rand() % (x - 3) + 2; // between 2 and x
        if (powerMod(a, x - 1, x) != 1) return false;
    }
    return true;
}

template <typename T>
int HashTable<T>::powerMod(int base, int exponent, int mod) const { // O(log exponent)
    // https://www.geeksforgeeks.org/modular-exponentiation-power-in-modular-arithmetic/
    // Ex:
        // 3^5 % 6 =
        // (3^4 * 3^1) % 6 =
        // ((3 * 3 % 6) * (3 * 3 % 6)) * (3^1 % 6) =
    int64_t result = 1;
    base %= mod;
    while (exponent) {
        if (exponent & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exponent >>= 1;
    }
    return result;
}

template <typename T>
unsigned int HashTable<T>::hash(const string& value) const {
    int hash = 3251; // Random prime
    for (char c : value) {
        if (c > 0) { // Sometimes the string is corrupted with negative values.
            hash = ((hash << 3) - hash) + c; // hash * 7 + c
        }
    }
    return hash;
}

// Sometimes strings are corrupted with negative values.
/*
When you download the txt file from github it can have hidden characters in front(239, 187, 191).
Those bytes are the UTF-8 Byte Order Mark (BOM), often added by some text editors.
This code is used to ignore any strings with those bytes.
*/
template <typename T>
bool HashTable<T>::isStrEql(string value1, string value2) const {
    int i1 = 0;
    int i2 = 0;
    while (value1[i1] || value2[i2]) {
        if (value1[i1] < 0) {
            i1++;
            continue;
        }
        if (value2[i2] < 0) {
            i2++;
            continue;
        }
        if (value1[i1] != value2[i2]) return false;
        i1++;
        i2++;
    }
    return true;
}
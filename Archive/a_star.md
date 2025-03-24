```C++
#pragma once

#include <vector>
#include <functional>
#include <cmath>

using namespace std;

struct Direction {
	int dRow = 0;
	int dCol = 0;

	bool operator==(const Direction& rhs) const {
		return dRow == rhs.dRow && dCol == rhs.dCol;
	}
	bool operator!=(const Direction& rhs) const {
		return !(*this == rhs);
	}
};

constexpr Direction _UP = {.dRow = -1, .dCol = 0};
constexpr Direction _DOWN = {1, 0};
constexpr Direction _RIGHT = {0, 1};
constexpr Direction _LEFT = {0, -1};
constexpr Direction _NONE = {0, 0};

struct Path {
	vector<vector<Direction>> path;
	int length;
	int headRow;
	int headCol;
};

class AStarNode {
	public:
		AStarNode(int row, 
				  int col, 
				  int gCost, 
				  int endRow, 
				  int endCol, 
				  AStarNode* parentNode = nullptr, 
				  Direction directionFromParent = _NONE
		);

		bool lessThanWithLength(const AStarNode& rhs, int length) const;
		bool operator==(const AStarNode& rhs) const;

		int fCost() const { return _gCost + _hCost; } // Estimated length for whole path
		int lCost(int length) const { return abs(fCost() - length); } // Estimated difference between current estimated path length and the length you want 
		int gCost() const { return _gCost; }
		void setGCost(int gCost) { _gCost = gCost; }
		int hCost() const { return _hCost; }
		void setHCost(int hCost) { _hCost = hCost; }
		int row() const { return _row; }
		int col() const { return _col; }
		AStarNode* parent() const { return _parent; }
		void setParent(AStarNode* parent) { _parent = parent; }
		Direction directionFromParent() const { return _directionFromParent; }
		void setDirectionFromParent(Direction directionFromParent) { _directionFromParent = directionFromParent; }
		
	private:
		int _gCost; // How far from starting node
		int _hCost; // How far from ending node
		int _row;
		int _col;
		AStarNode* _parent;
		Direction _directionFromParent;
};

class AStar {
	public:
		static Path aStar(int startRow, 
						  int startCol, 
						  function<bool(int, int)> intersects, 
						  int gridRow, 
						  int gridCol, 
						  int endRow, 
						  int endCol, 
						  int minPathLength = 0
		);
		static void printPath(Path path);
		static int pathLengthToCell(Path path, int cellRow, int cellCol);
		static Path combinePaths(Path pathA, Path pathB, int gridRow, int gridCol);
	private:
		static constexpr Direction directions[4] = {_UP, _DOWN, _RIGHT, _LEFT};
		
		// Determins if the row and col are obstacles based upon the intersects function
		static bool isObstacle(function<bool(int, int)> intersects, 
							   int gridRow, 
							   int gridCol, 
							   int row, 
							   int col
		);
		// Used to find the AStarNode pointer that has those row and col
		static AStarNode* findInAStarNodeVector(const vector<AStarNode*>& vec, 
												int row, 
												int col
		);
};

```

```C++
#include "AStar.h"
#include <algorithm>

#include <iostream>

// AStarNode---------------------------------------------------------

AStarNode::AStarNode(int row, 
					 int col, 
					 int gCost, 
					 int endNodeRow, 
					 int endNodeCol, 
					 AStarNode* parent, 
					 Direction directionFromParent
) {
	_row = row;
	_col = col;
	_gCost = gCost;
	_hCost = abs(row - endNodeRow) + abs(col - endNodeCol); // Manhaton Distance
	_parent = parent;
	_directionFromParent = directionFromParent;
}

bool AStarNode::lessThanWithLength(const AStarNode& rhs, int length) const {
	// Less than based on the lCost
	// If they are the same then use the hCost
	return (lCost(length) < rhs.lCost(length)) || (lCost(length) == rhs.lCost(length) && _hCost < rhs.hCost());
}

bool AStarNode::operator==(const AStarNode& rhs) const {
	return _row == rhs.row() && _col == rhs.col();
}

// AStar-----------------------------------------------------------------------

bool AStar::isObstacle(function<bool(int, int)> intersects, 
					   int gridRow, 
					   int gridCol, 
					   int row, 
					   int col
) {
	int rows = gridRow;
	int cols = gridCol;
	// Check if it's within the bounds of the board
	if (row < 0 || row >= rows || col < 0 || col >= cols) return true;
	// Check if it intersects with the snake
	if (intersects(row, col)) return true;
	return false;
}

AStarNode* AStar::findInAStarNodeVector(const vector<AStarNode*>& vec, 
									    int row, 
										int col
) { // Linear search
	for (AStarNode* node : vec) {
		if (node->row() == row && node->col() == col) {
			return node;
		}
	}
	return nullptr;
}

Path AStar::aStar(int startRow, 
				  int startCol, 
				  function<bool(int, int)> intersects, 
				  int gridRow, 
				  int gridCol, 
				  int endRow, 
				  int endCol, 
				  int minPathLength
) {
	vector<vector<Direction>> aStarPath(gridRow, vector<Direction>(gridCol, _NONE));
	int pathLength = 0;
	// Create nodesToCheck and nodesAlreadyChecked
	vector<AStarNode*> nodesToCheck;
	vector<AStarNode*> nodesAlreadyChecked;
	// Create start node and add it to nodesToCheck
	AStarNode* startNode = new AStarNode(startRow, startCol, 0, endRow, endCol);
	nodesToCheck.push_back(startNode);
	// while there are still nodesToCheck
	while (!nodesToCheck.empty()) {
		// Get curNode
			sort(nodesToCheck.begin(), nodesToCheck.end(), [&](AStarNode* a, AStarNode* b) {
				return a->lessThanWithLength(*b, minPathLength);
			});
			AStarNode* curNode = nodesToCheck.front();
			nodesToCheck.erase(nodesToCheck.begin());
			nodesAlreadyChecked.push_back(curNode);
		// Check if the goal is reached
		if (curNode->row() == endRow && curNode->col() == endCol) {
			// Check the path length
			if ((curNode->gCost() + 1) >= minPathLength) {
				// Reconstruct the a star path
				while (curNode != nullptr) {
					if (curNode->directionFromParent() != _NONE) {
						aStarPath[curNode->parent()->row()][curNode->parent()->col()] = curNode->directionFromParent();
						pathLength++;
					}
					curNode = curNode->parent();
				}
				break;
			}
		}
		// For each of the curNode's neighbors
		for (int neighborI = 0; neighborI < 4; neighborI++) {
			Direction neighborDirection = directions[neighborI];
			int neighborRow = curNode->row() + neighborDirection.dRow;
			int neighborCol = curNode->col() + neighborDirection.dCol;
			// Check if the neighbor is valid
				// Check if the neighbor is an obstacle, but allow the end to be an obstacle
				bool isEnd = (neighborRow == endRow && neighborCol == endCol);
				if (isObstacle(intersects, gridRow, gridCol, neighborRow, neighborCol) && !isEnd) continue;
				// Check if the neighbor is in nodesAlreadyChecked
				if (findInAStarNodeVector(nodesAlreadyChecked, neighborRow, neighborCol)) continue;
			// Calculate costToNeighbor
			int costToNeighbor = curNode->gCost() + 1;
			// Check if neighbor isn't in nodesToCheck
			AStarNode* neighbor = findInAStarNodeVector(nodesToCheck, neighborRow, neighborCol);
			if (!neighbor) {
				// Create neighbor
				AStarNode* newNeighbor = new AStarNode(neighborRow, 
													   neighborCol, 
													   costToNeighbor, 
													   endRow, 
													   endCol, 
													   curNode, 
													   neighborDirection
				);
				// Add neighbor to nodesToCheck
				nodesToCheck.push_back(newNeighbor);
			} else if (costToNeighbor < neighbor->gCost()) {
				// Update neighbor
				neighbor->setGCost(costToNeighbor);
				neighbor->setParent(curNode);
				neighbor->setDirectionFromParent(neighborDirection);
			}
		}
	}
	// Delete all heap memory
	for (AStarNode* node : nodesToCheck) delete node;
	for (AStarNode* node : nodesAlreadyChecked) delete node;

	Path path;
	path.path = aStarPath;
	path.length = pathLength;
	path.headRow = startRow;
	path.headCol = startCol;
	return path;
}

void AStar::printPath(Path path) {
	for (vector<Direction> cols : path.path) {
		for (Direction direction: cols) {
			char drawnChar;
			if (direction == _UP) drawnChar = '^';
			else if (direction == _DOWN) drawnChar = 'v';
			else if (direction == _RIGHT) drawnChar = '>';
			else if (direction == _LEFT) drawnChar = '<';
			else drawnChar = '.';
			clog << drawnChar << " ";
		}
		clog << "\n";
	}
}

int AStar::pathLengthToCell(Path path, int cellRow, int cellCol) {
	int length = 0;
	int curHeadRow = path.headRow;
	int curHeadCol = path.headCol;
	Direction directionToFollow;
	// Follow path until you find row and col
	while (true) {
		if (curHeadRow == cellRow && curHeadCol == cellCol) return length;
		// If not the location, then go to the next one if available
		directionToFollow = path.path[curHeadRow][curHeadCol];
		if (directionToFollow == _NONE) break;
		curHeadRow += directionToFollow.dRow;
		curHeadCol += directionToFollow.dCol;
		length++;
	}
	// Path does not go to that location
	return -1;
}

Path AStar::combinePaths(Path pathA, Path pathB, int gridRow, int gridCol) {
	vector<vector<Direction>> path(gridRow, vector<Direction>(gridCol, _NONE));
	int length = 0;
	for (int rowI = 0; rowI < gridRow; rowI++) {
		for (int colI = 0; colI < gridCol; colI++) {
			Direction pathADirection = pathA.path[rowI][colI];
			Direction pathBDirection = pathB.path[rowI][colI];
			if (pathADirection != _NONE) {
				path[rowI][colI] = pathADirection;
				length++;
			} else if (pathBDirection != _NONE) {
				path[rowI][colI] = pathBDirection;
				length++;
			}
		}
	}
	Path p;
	p.path = path;
	p.length = length;
	p.headRow = pathA.headRow;
	p.headCol = pathA.headCol;
	return p;
}



```
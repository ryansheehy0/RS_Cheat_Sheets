[Home](../README.md)

# Low level concepts

<!-- TOC -->

- [Memory sizes](#memory-sizes)
- [Number systems](#number-systems)
	- [Definitions](#definitions)
	- [Hex](#hex)
	- [Converting](#converting)
- [Unsigned ints](#unsigned-ints)
	- [Addition](#addition)
	- [Subtractions](#subtractions)
- [Signed ints/2's complement](#signed-ints2s-complement)
	- [Addition](#addition)
	- [Subtractions](#subtractions)
- [Floats](#floats)
	- [Convert decimal to float](#convert-decimal-to-float)
	- [Special cases](#special-cases)
- [Bitwise](#bitwise)
	- [Shifting ops](#shifting-ops)
- [Masking ops](#masking-ops)

<!-- /TOC -->

## Memory sizes
- Unsigned ints are useful for representing memory locations
- A base 2 width 32 computer(32bit architecture) can address 2^32 different memory locations with each memory location holding 1 byte(8 bits).
	- This is RAM space, not hard drive space.

Binary units
| Number of bytes | Symbol | Name     |
|-----------------|--------|----------|
| 2^10            | 1 KiB  | Kibibyte |
| 2^20            | 1 MiB  | Mebibyte |
| 2^30            | 1 GiB  | Gibibyte |
| 2^40            | 1 TiB  | Tebibyte |
| 2^50            | 1 PiB  | Pebibyte |
| 2^60            | 1 EiB  | Exbibyte |

Decimal units
| Number of bytes | Symbol | Name     |
|-----------------|--------|----------|
| 10^3            | 1 KB   | Kilobyte |
| 10^6            | 1 MB   | Megabyte |
| 10^9            | 1 GB   | Gigabyte |
| 10^12           | 1 TB   | Terabyte |
| 10^15           | 1 PB   | Petabyte |
| 10^18           | 1 EB   | Exabyte  |

- Ex 1: 32bit architecture
	- 2^32 = 2^2 * 2^30 = 4 GiB = 4.294967 GB
- Ex 2: 48bit architecture
	- 2^48 = 2^8 * 2^40 = 256 TiB = 281.475 TB
	- Most 64bit CPUs are actually 48bit architectures.

## Number systems
Each number system has 3 characteristics:
- Symbols Ex: {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
- Base(b)/Radix Ex: 10
- Weights Ex: 96.12 = 9(10^1) + 6(10^0) + 1(10^-1) + 2(10^-2)
	- Weights are the b^index

### Definitions
- Number - An array of symbols.
- Width(w)/length/word size - Number of digits that can be processed in a single operation.
- The largest number for a given base(UMAX) = b^w - 1
	- Minus 1 because 0 counts as a number
- Overflow(OV) - When the number cannot fit inside the word size of the computer.
- Most Significant Bit(MSB) - The leading bit of the word.

### Hex
- Symbols: {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F}
- Base: 16
- Conversions
	- A = 10 = 1010
	- B = 11 = 1011
	- C = 12 = 1100
	- D = 13 = 1101
	- E = 14 = 1110
	- F = 15 = 1111

### Converting
- Decimal to Binary
	- Successive division by 2 with the remainder being the next binary digit.
	- Subtract the largest power of 2 and put a 1 in its corresponding index.
		- Ex: 97 -> 97 - 64 -> 33 - 32 -> 1 to binary is 0110 0001
- Decimal to Hex
	- Successive division by 16 with the remainder being the next hex digit.
	- Ex: 314,156
		- 314,156 = 19,634 * 16 + 12			12 = C
		- 19,634 = 1,227 * 16 + 2					2
		- 1,227 = 76 * 16 + 11						11 = B
		- 76 = 4 * 16 + 12								12 = C
		- 4 = 0 * 16 + 4									4
		- 314,156 decimal is 0x4CB2C Hex
- Binary to Decimal
	- Multiply each digit with its weight(2^index)
- Binary to Hex
	- Split into 4 bit sections and replace each one with its hex symbol.
- Hex to Decimal
	- Multiply each digit with its weight
	- Ex: 0x4CB2C = 12(16^0) + 2(16^1) + 11(16^2) + 12(16^3) + 4(16^4) = 314,156
- Hex to Binary
	- Replace each hex symbol with its binary equivalent.

**Make sure to get the base and order of numbers right when converting!!!**

## Unsigned ints
### Addition

Example:
1
  8 2 6 3      3 + 8 = 11 = B
+ C 6 9 8      6 + 9 = 15 = F
---------      2 + 6 = 8
  4 8 F B      8 + C = 8 + 12 = 20 = 16 + 4 = 0x14
	With OV

### Subtractions
- A negative/opposite number is defined as the number added to another to produce 0.
	- Computers allows two positive numbers added together to produce 0 by way of overflowing.
- Overflow happens if the 2nd number is greater than the 1st number.
1. Find the opposite of the negative number
	1. Subtract each hex with F
	2. Add 1
2. Add the opposite together

Example:
  F F 6 3
- E A 7 F
---------

Opposite(0xEA7F) = 0x1580 + 1 = 0x1581
	F - F = 0
	F - 7 = 15 - 7 = 8
	F - A = 15 - 10 = 5
	F - E = 15 - 14 = 1

1 1
  F F 6 3      F + 5 = 15 + 5 = 20 = 16 + 4 = 0x14
+ 1 5 8 1      1 + F + 1 = 1 + 15 + 1 = 16 + 1 = 0x11
---------
  1 4 E 4

## Signed ints/2's complement
- The weight of the MSB is always negative
	- Ex: word size of 4 bits 1111 = 1(1) + 1(2) + 1(4) + 1(-8) = -1
	- All 1s is always -1
- 2's complement allows for binary addition of signed numbers to give accurate results.
- To convert between signs in 2's complement'
	- Complement - Flips all the bits
	- Add 1
	- Ex: 1111 = -1, 0000 + 1 = 0001 = 1, 1110 + 1 = 1111

### Addition
- Any most significant hex above or equal to 8 is negative because the MSB is 1.
- Overflows
	- Overflow can never happen when the numbers are opposite signs
	- Overflows can only happen when the numbers are the same sign, but the result is a different sign then the other two numbers.

Example:
1 1 1
  8 3 D 1      D + 3 = 13 + 3 = 16 = 0x10
+ 8 F 3 7      1 + 3 + F = 1 + 3 + 15 = 19 = 16 + 3 = 0x13
---------      1 + 8 + 8 = 17 = 16 + 1 = 0x11
  1 3 0 8

0x83D1 is neg
0x8F37 is neg
0x1308 is pos therefore, there is an overflow.

### Subtractions
1. Convert the subtraction number to it's 2's complement, aka reverse its sign.
2. Add them together

Example:

  F F 2 9
- 2 3 9 F
---------

2's complement(0x239F)
	0x239F    = 0010 0011 1001 1111
  complement: 1101 1100 0110 0000
	Add 1:      1101 1100 0110 0001
                D    C    6    1
1 1
  F F 2 9      F + C = 15 + 12 = 27 = 16 + 11 = 0x1B
+ D C 6 1      1 + F + D = 1 + 15 + 13 = 29 = 16 + 13 = 0x1D
---------
  D B 8 A

0xFF29 is neg
0xDC61 is neg
0xDB8A is neg therefore, there is no overflow.

## Floats
- IEEE(Institute of Electrical and Electronics Engineers) has RFCs(Request for Comment). Floats have the RFC of 754.

_ ________ _______________________
| \8 bits/ \       23 bits       /     = 32 bits
|    |               |
|    |               Mantissa/Fraction
|    Biased exponent
Sign bit

- 64 bit float has 11 bits as the biased exponent.
- The Mantissa/Fraction doesn't need to include the 1. because it can be assumed.

### Convert decimal to float
1. Get the sign bit
2. Get the biased exponent
	1. Successively divide by 2 until you get 1.##
	2. The number of times you divide by 2 is the exponent
	3. Add 127(2^7 - 1) for 32 bit or 1023(2^10 - 1) for 64 bit to the exponent to get the biased exponent
	4. Convert the biased exponent to binary
3. Find the fraction
	1. Successively multiply the fraction by 2 and take the first digit as 1 or 0
	2. Do this until you find 23 bits for 32 bit float or 52 bits for 64 bit float.
		- If you can find a pattern, then this can reduce your amount of calculations.
4. Combine all the bits together and convert into hex

Example:
Convert 4.56 to 32 bit float.

Sign: 0

4.56 / 2 = 2.28
2.28 / 2 = 1.14
4.56 = 1.14 * 2^2

Biased exponent = 2 + 127 = 129 = 1000 0001

0.14 * 2 = 0.28   -> 0           1
0.28 * 2 = 0.56   -> 0 --        2
0.56 * 2 = 1.12   -> 1  |        3

0.12 * 2 = 0.24   -> 0  |        4
0.24 * 2 = 0.48   -> 0  |        5
0.48 * 2 = 0.96   -> 0  |        6
0.96 * 2 = 1.92   -> 1  |        7

0.92 * 2 = 1.84   -> 1  |        8
0.84 * 2 = 1.68   -> 1  |        9
0.68 * 2 = 1.36   -> 1  |        10
0.36 * 2 = 0.72   -> 0  | Cycle  11

0.72 * 2 = 1.44   -> 1  |        12
0.44 * 2 = 0.88   -> 0  |        13
0.88 * 2 = 1.76   -> 1  |        14
0.76 * 2 = 1.52   -> 1  |        15

0.52 * 2 = 1.04   -> 1  |        16
0.04 * 2 = 0.08   -> 0  |        17
0.08 * 2 = 0.16   -> 0  |        18
0.16 * 2 = 0.32   -> 0  |        19

0.32 * 2 = 0.64   -> 0  |        20
0.64 * 2 = 1.28   -> 1 --        21
         = 0.56   -> 0           22
         = 1.12   -> 1           23

Fraction: 001 0001 1110 1011 1000 0101

32 bit float: 0 1000 0001 001 0001 1110 1011 1000 0101
              0100 0000 1001 0001 1110 1011 1000 0101
                4    0    9    1    E    B    8    5
              0x4091EB85

### Special cases
- If exponential field is all 1s and fraction field is all 0s, then it's +/- infinite.
- If exponential field is all 1s and fraction field is non 0, then it's a NaN.
- If exponential field is all 0s, then the fraction is implied without a leading 1.
	- Ex: -0.75 = 1 0000 0000 110 0000 0000 0000 0000 0000
	- Has to be in the form of 0.#. If it's 0.0#, then use negative exponents.

Example of a negative exponent:
-0.043 = 1.372 * 2^-5

Sign: 1
Biased exponent = -5 + 127 = 122 = 0111 1010
Fraction
	0.372 * 2 = 0.744   -> 0
	0.744 * 2 = 1.488   -> 1
	0.488 * 2 = 0.976   -> 0
	                    -> etc.


- Questions
	- Why biased by 127 and not 128?
		- What is -1? 1111 1111?
	- Why is NaN necessary?
	- Exponent of -127 is a special case


## Bitwise
- Setting a bit to 1
	- var |= 0x4;
- Setting a bit to 0
	- var &= ~0x4;
- Toggling a bit
	- var ^= 0x4;
- Check if a bit is set
	- bool isSet = var & 0x4;

### Shifting ops

| Operation           | Example 1 | Example 2 |
|---------------------|-----------|-----------|
| x                   | 0011 0011 | 1011 0011 |
| x << 4              | 0011 0000 | 0011 0000 |
| x >> 4 (logical)    | 0000 0011 | 0000 1011 |
| x >> 4 (arithmetic) | 0000 0011 | 1111 1011 |

- Arithmetic right shift shifts in the value of the most significant bit. Used for signed ints.
	- In java >> is arithmetic and >>> is logical

### Masking ops
- x & 0xFF gets the last byte
- x & ~0x0 gets all they bytes which is size independent.
- x & ~0xFF all but the least significant byte.
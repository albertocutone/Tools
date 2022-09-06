//Bitwise operations
// Ref. https://leetcode.com/problems/sum-of-two-integers/discuss/84278/A-summary%3A-how-to-use-bit-manipulation-to-solve-problems-easily-and-efficiently


//shift left i-times (multiply by 2 i-times)
// (1 << i)
//  '0001' << 1 -> '0010' = 2
//  '0001' << 2 -> '0100' = 4
//shift right i-times (divide by 2 i-times)
// (1 >> i)
//  '0010' << 1 -> '0001' 
// Returns only the bits that are set in both the left and the right operand ->
// A & B
// eg 5 & 4 = 0101 & 0100 = 0100 = 4
// If A & B = 0 -> A,B do not share any bit. if they do, A&B!=0

// Check if the i-th bit of a binary number is set to 1:
// x & (1 << i) -> if 0, the bit is not set to 1

// Set the i-th bit of a binary number x to 1:
// x = x | ( 1 << i )

// Check if x is power of 2 ->
// ( x & ( x - 1 ) ) == 0
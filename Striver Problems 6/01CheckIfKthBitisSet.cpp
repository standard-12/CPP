#include<bits/stdc++.h>
using namespace std;

// This is left shift approach
class Solution {
  public:
    bool checkKthBit(int n, int k) {
            return (n & 1<<k) != 0; // True if k th bit is set
    }
};

// For right shift approach i tried But IT WAS WRONG
class Solution {
  public:
    bool checkKthBit(int n, int k) {
            return n & INT_MIN>>(32-k); // But this doesn't work like that because C++ for signed integer when right shifting add's 1
            // I.e if INT_MIN is 10000...0 and INT_MIN >> 2 gives 11100000...0  
    }
};

// The right shift method 
class Solution {
  public:
    bool checkKthBit(int n, int k) {
            return n >> k & 1;
    }
};


// RIGHT SHIFT RULES
// For positive numbers → always safe, behaves like division
// For negative numbers → depends on compiler (usually arithmetic shift)

// LEFT SHIFT RULES
// Case 1 (signed, positive, no overflow): n << k works like multiplying by 2^k and is safe as long as the result stays within range.
// Case 2 (signed, overflow): If shifting causes the value to exceed the signed int range (e.g., 1 << 31), the behavior is undefined.
// Case 3 (signed, negative value): Left shifting a negative signed integer is undefined behavior regardless of the result.
// Case 4 (unsigned): For unsigned integers, left shift is always well-defined and shifts bits left with zero fill, following modulo 2^n arithmetic.
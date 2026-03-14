#include<bits/stdc++.h>
using namespace std;

// The idea is we need not check the whole number we can only check if the mod is divisble by k this is possible because 
// The equation of no's having only 1's
// N (k) = N(k-1)*10+1   N(k) is the number with only 1 having k 1's i.e k is the no of digits 
//  111 = 11 * 10 + 1
// We know that ( a mod n * b mod n ) mod n = (a*b)modn
// Then N(k) mod n = (N (k-1) * 10 + 1) mod n
//      N(k) mod n = (N(k-1) mod n * 10 +1) mod n

// And also we loop till k because only k remainders are possible for k and if there is any repeation of remainders then there won't be solution
// Because same pattern will repeat again
class Solution {
public:
    int minAllOneMultiple(int k) {
        if(k%2==0 || k%5==0) return -1;
        int rem = 0;
        for (int i = 1; i <= k; i++) {
            rem = (rem * 10 + 1) % k;
            if (rem == 0) return i;
        }
        return -1;
    }
};
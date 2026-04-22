#include<bits/stdc++.h>
using namespace std;

// This was my first solution

class Solution {
public:
    int hammingWeight(int n) {
        int cnt=0;
        if(n<0) return false;
        for(int i=0;i<31;i++){
            int a = 1<<i;
            if ( a & n) cnt++;
        }
        return cnt;
    }
};

// This is the solution based on the prev questions

class Solution {
public:
    int hammingWeight(int n) {
        int cnt=0;
        while(n != 0){
            n= n & (n-1);
            cnt++;
        }
        return cnt;
    }
};

// Based on decimal to binary conversion method ( long divison method )
class Solution {
public:
    int hammingWeight(int n) {
        int cnt=0;
        while(n > 0){
            if(n&1) cnt++; // if n is odd 
            n=n>>1; // divide by 2
        }
        return cnt;
    }
};

// All the above have time complexity of O(31)
// For first time complexity O(31) directly
// Second time complexity is O(no of bits set) hence worst case O(31)
// For third one time complexity is O(log n) where n is int and hence worst case (n == INT_MAX) time complexity will be O(31)
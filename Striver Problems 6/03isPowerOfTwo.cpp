#include<bits/stdc++.h>
using namespace std;

// This was my first solution but this fails for INT_MIN;
class Solution {
public:
    bool isPowerOfTwo(int n) {
        int cnt=0;
        for(int i=0;i<32;i++){ 
            int a = 1<<i; 
            if ( a & n) cnt++;
        }
        return cnt==1;
    }
};

// just added a case for neg numbers
class Solution {
public:
    bool isPowerOfTwo(int n) {
        int cnt=0;
        if(n<0) return false;
        for(int i=0;i<31;i++){
            int a = 1<<i;
            if ( a & n) cnt++;
        }
        return cnt==1;
    }
};

// The elegant one & the optimal one 
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0 && (n & (n-1))==0;
    }
};
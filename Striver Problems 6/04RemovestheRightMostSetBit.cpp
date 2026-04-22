#include<bits/stdc++.h>
using namespace std;

// This works because if no is n=10010100 then n-1=10010011 
class Solution {
public:
    int removeRightMost(int n) {
        return n & n-1;
    }
};
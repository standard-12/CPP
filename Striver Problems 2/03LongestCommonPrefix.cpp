#include<bits/stdc++.h>
using namespace std;


// This is divide and conquer method i just saw it for learnign this method 

class Solution {
public:
    // Helper to find LCP of two strings
    string lcpOfTwo(const string &a, const string &b) {
        int len = min(a.size(), b.size());
        int i = 0;
        while (i < len && a[i] == b[i]) i++;
        return a.substr(0, i);
    }

    // Recursive divide & conquer
    string lcpDivide(vector<string>& strs, int l, int r) {
        if (l == r) return strs[l];   // only one string
        int mid = (l + r) / 2;
        string left = lcpDivide(strs, l, mid);
        string right = lcpDivide(strs, mid + 1, r);
        return lcpOfTwo(left, right);
    }

    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        return lcpDivide(strs, 0, strs.size() - 1);
    }
};

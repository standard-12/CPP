#include<bits/stdc++.h>
using namespace std;

// This was my brute force solution comparing the rotations with the goal
// Time Complexity O(n^2) Space Complexity O(n) for copying string
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s==goal) return true;
        int size=s.size();
        for(int k=1;k<size;k++){// compare from k=1
        string nums=s;
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
        reverse(nums.begin(),nums.end());
        if(nums.compare(goal)==0) return true; 
        }
        return false;
    }
};

// This is the optimal solution
// time complexity is O(n^2) in worst case but for most of the cases it is O(n) with .find() (may be it uses Booyer-Moore)
// if we want guarantedd O(n) we should use KMP algorithm
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;
        s=s+s;
        return s.find(goal)!=string::npos;
    }
};
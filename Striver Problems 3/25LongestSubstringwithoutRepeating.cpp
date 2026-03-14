#include<bits/stdc++.h>
using namespace std;

// This was my solution the time complexity is O(2n) and Space Complexity is O(128)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int i=0;
        int j=0;
        unordered_set<char> st;
        int maxi=0;
        while(i<n && j<n){
            while(j<n && !st.count(s[j])){
                st.insert(s[j]);
                maxi=max(maxi,j-i+1);
                j++;
            }
            while(i<n && st.count(s[j])){
                st.erase(s[i]);
                i++;
            }
        }
        return maxi;
    }
};

// This is the optimal solution using vector 
// Time complexity O(n) because we are not incrementing both i and j on every step and Space Complexity O(128)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int i=0;
        int j=0;
        vector<int> vec(128,-1);
        int maxi=0;
        while(i<n && j<n){
            if(vec[s[j]]>=0 && vec[s[j]]>=i){
                i=vec[s[j]]+1;
            }
            vec[s[j]]=j;
            maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};
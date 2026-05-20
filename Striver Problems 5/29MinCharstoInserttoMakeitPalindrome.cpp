#include<bits/stdc++.h>
using namespace std;

// This was hard que but i figured it can be solved using LCS because it is said we can insert the chars at any place and any char
// So we should see the longest palindromic subsequence ( the remaining letters are to be added at some appropriate place doesn't matter where for our problem)
// To make it Palindromic

class Solution {
public:
    int minInsertions(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        int n=s.size();
        vector<int> curr(n+1,0),prev(n+1,0);

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==t[j-1]){
                    curr[j]=1+prev[j-1];
                }
                else {
                    curr[j]=max(curr[j-1],prev[j]);
                }
            }
            prev=curr;
        }
        return n-prev[n]; // Only change
    }
};
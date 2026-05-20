#include<bits/stdc++.h>
using namespace std;

// This was the question 
// Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.
// In one step, you can delete exactly one character in either string.

// I was able to figure out this was also a pattern of LCS 

// Hence i solved it 
class Solution {
public:
    int minDistance(string word1, string word2) {
        string s=word1;
        string t=word2;
        int n1=s.size();
        int n2=t.size();
        vector<int> curr(n2+1,0),prev(n2+1,0); // And here both should be of same size

        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(s[i-1]==t[j-1]){
                    curr[j]=1+prev[j-1];
                }
                else {
                    curr[j]=max(curr[j-1],prev[j]);
                }
            }
            prev=curr;
        }
        int LCS=prev[n2];
        return (n1-LCS)+(n2-LCS); // This is the only change 
    }
};
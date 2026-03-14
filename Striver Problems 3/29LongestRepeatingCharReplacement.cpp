#include<bits/stdc++.h>
using namespace std;

// This was my solution and it got accepted in the first try but this is not the optimal solution

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<26;i++){
            ans=max(ans,maxCntforChar(s,'A'+i,k));
        }        
        return ans;
    }

    int maxCntforChar(string& s,char ch,int k){
        int n=s.size();
        int i=0;
        int j=0;
        int maxLen=0;
        int flips=0;
        while(j<n){
            if(s[j]!=ch) flips++;
            if(flips>k){
                if(s[i]!=ch) flips--;
                i++;
            } 
            if(flips<=k) maxLen=max(maxLen,j-i+1);
            j++;
        }
        return maxLen;
    }
};

// This is the optimal i mean we can replace the while with if directly here so this is the optimal 
// Idea is currentLength-maxFreq gives the no of characters to be replaced but we needNot calculate maxFreq when we shrink window because
// We are searching for a longer answer i.e we should be increasing the length and also the maxFreq 

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int i=0;
        vector<int> vec(26,0);
        int maxFreq=0;
        int ans=0;
        for(int j=0;j<n;j++){
            vec[s[j]-'A']++;
            maxFreq=max(maxFreq,vec[s[j]-'A']); // Update the max freq we are not worried about which letter has max frequency
            while( (j-i+1) - maxFreq > k) {// j-i+1 is the length of substring 
                vec[s[i]-'A']--;
                i++;  // We need not recalculate the maxFreq here
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};
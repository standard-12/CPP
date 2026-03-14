#include<bits/stdc++.h>
using namespace std;

// This solution is very nice and important 
// At first i was trying to write code for exactly K distinct character although i couldn't write but it would be very messy anyways
// It is easy to find at Most K characters substring so we find it for K and K-1 which gives the answer 

class Solution {
  public:
    int countSubstr(string& s, int k) {
        // code here
        if(k>(int)s.size()) return 0;
        return atMostK(s,k)-atMostK(s,k-1); // Very nice line
    }
    int atMostK(string& s,int k){
        int n=s.size();
        int i=0,j=0;
        int dist=0;
        int count=0;
        unordered_map<char,int> freq;
        while(j<n){
            if(freq[s[j]]==0) dist++;
            freq[s[j]]++;
            
            while(dist>k){
                freq[s[i]]--;
                if(freq[s[i]]==0) dist--;
                i++;
            }
            count+=j-i+1; // Count substrings that will be added at each step
            j++;
        }
        return count;
    }
};
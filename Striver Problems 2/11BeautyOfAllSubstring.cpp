#include<bits/stdc++.h>
using namespace std;

// This also i couldnt solve myself i was thinking this can be solved with O(n) so was thinking of that 
// still in brute force i colud'nt come with the freq(26,0) array optimization i was thinking of brute force with O(n^3)

class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            vector<int> freq(26,0);
            for(int j=i;j<n;j++){
                freq[s[j]-'a']++;
                int mini=INT_MAX;
                int maxi=0;
                for(int k=0;k<26;k++){
                    if(freq[k]>0){
                    mini=min(mini,freq[k]);
                    maxi=max(maxi,freq[k]);
                    }
                }
                ans+=(maxi-mini);
            }
        }
        return ans;
    }
};
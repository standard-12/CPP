#include<bits/stdc++.h>
using namespace std;

// Yeee i solved it on my own hurray 
// The key idea was to sort the array according to length of the string and then it's similar to last problem
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        struct cmp{
            bool operator()(const string& a,const string& b){
                return a.size() < b.size();
            }
        };
        int n=words.size();
        sort(words.begin(),words.end(),cmp());
        vector<int> dp(n,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int size=words[j].size();
                if(size+1==words[i].size()){
                    if(check(words[i],words[j])){
                        dp[i]=max(dp[i],1+dp[j]);
                    }
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }

    bool check(string& a,string& b){
        int i=0,j=0;
        int small=b.size();
        int insertions=0;
        while(j<small){
            if(a[i]==b[j]){
                i++;
                j++;
            }
            else {
                insertions++;
                i++;
            }
            if(insertions>1) return false;
        }
        return true;
    }
};
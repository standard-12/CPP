#include<bits/stdc++.h>
using namespace std;

// I couldn't solve this To be honest i couldn't even understand this completely
class Solution {
public:
    map<pair<int,int>, set<string>> memo;

    set<string> backtrack(string &s1, string &s2, int i, int j, vector<vector<int>>& dp){
        if(i==0 || j==0) return {""};

        if(memo.count({i,j})) return memo[{i,j}];

        set<string> result;

        if(s1[i-1] == s2[j-1]){
            auto temp = backtrack(s1,s2,i-1,j-1,dp);
            for(auto &str : temp){
                result.insert(str + s1[i-1]);
            }
        }
        else{
            if(dp[i-1][j] >= dp[i][j-1]){
                auto top = backtrack(s1,s2,i-1,j,dp);
                result.insert(top.begin(), top.end());
            }
            if(dp[i][j-1] >= dp[i-1][j]){
                auto left = backtrack(s1,s2,i,j-1,dp);
                result.insert(left.begin(), left.end());
            }
        }

        return memo[{i,j}] = result;
    }

    vector<string> allLCS(string &s1, string &s2) {
        int n1=s1.size(), n2=s2.size();

        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(s1[i-1]==s2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }

        set<string> res = backtrack(s1,s2,n1,n2,dp);

        return vector<string>(res.begin(), res.end());
    }
};
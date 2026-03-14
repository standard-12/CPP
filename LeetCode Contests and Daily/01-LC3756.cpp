#include<bits/stdc++.h>
using namespace std;

// This is the brute force solution
class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n=queries.size();
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            int an=answer(s,queries[i][0],queries[i][1]);
            ans[i]=an;
        }
        return ans;
    }

    int answer(string& s,int l,int r){
        int MOD=1e9+7;
        int nn=0;
        int sum=0;
        int i=l;
        while(i<=r){
            int dig=s[i]-'0';
            if(dig!=0) nn=(1LL*nn*10%MOD+dig)%MOD;
            sum+=dig;
            i++;
        }
        return (1LL* nn%MOD * sum%MOD) % MOD;
    }
};
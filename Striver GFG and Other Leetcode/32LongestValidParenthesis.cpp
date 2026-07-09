#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        int left=0,right=0,maxi=0;

        for(int i=0;i<n;i++){
            if(s[i]=='(') left++;
            else right++;
            if(right>left){
                left=0;
                right=0;
            }
            else if( left==right){
                maxi=max(maxi,left+right);
            }
        }
        left=0,right=0;
        for(int i=n-1;i>0;i--){
            if(s[i]==')') right++;
            else left++;

            if(left>right){
                left=0;
                right=0;
            }
            else if(left==right){
                maxi=max(maxi,left+right);
            }
        }
        return maxi;
    }
};

class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();

        vector<int> dp(n+2,0);
        for(int i=n-1;i>=0;i--){
            if(s[i]==')') continue;

            if(i+1<n && s[i+1]==')'){
                dp[i]=2+dp[i+2];
            }

            else {
                int x=dp[i+1];
                int idx=i+x+1;

                if(idx<n && s[idx]==')'){
                    dp[i]=2+x+dp[idx+1];
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};
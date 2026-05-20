#include<bits/stdc++.h>
using namespace std;

// I had found the right idea that is to find the LCS string and then combine missing chars from both s1 and s2
// But i missed some small things like i didn't reverse the LCS string built (i had built it in reverse order but forgot to reverse it etc)
// Also my logic of combining both strings was not right 
// This is the final solution 
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n1=str1.size();
        int n2=str2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        string LCS="";
        int i=n1,j=n2;
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                LCS+=str1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }
            else {
                j--;
            }
        }
        reverse(LCS.begin(),LCS.end());  // Imp since we are building it in reverse order ( Can we build it in right order?)

        string ans="";
        int p1=0,p2=0;
        int lcs=0;
        while(lcs<LCS.size()){
            while(p1<str1.size() && str1[p1]!=LCS[lcs]){
                ans+=str1[p1];
                p1++;
            }
            while(p2<str2.size() && str2[p2]!=LCS[lcs]){
                ans+=str2[p2];
                p2++;
            }
            ans+=LCS[lcs];
            p1++;
            p2++;
            lcs++;
        }
        while(p1<str1.size()){
            ans+=str1[p1];
            p1++;
        }
        while(p2<str2.size()){
            ans+=str2[p2];
            p2++;
        }
        return ans;
    }
};

// We can build the answer while building the LCS itself
// Like below
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n1=str1.size();
        int n2=str2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        string ans="";
        int i=n1,j=n2;
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                ans+=str1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                ans+=str1[i-1];
                i--;
            }
            else {
                ans+=str2[j-1];
                j--;
            }
        }
        while(i>0) {
            ans+=str1[i-1];
            i--;
        }
        while(j>0){
            ans+=str2[j-1];
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
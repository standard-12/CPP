#include<bits/stdc++.h>
using namespace std;

// This is from LC and Strivers Frog jump is diff(it's the next que)
// I wrote this recursion on my own so happy about it 
// I knew this would give tle since constraint is n<=2000 
// 
class Solution {
public:
    bool canCross(vector<int>& stones) {
        if(stones[1]!=1) return false;
        return jumper(stones,1,1);
    }

    bool jumper(vector<int>& stones,int jump,int ind){
        if(ind==stones.size()-1) return true;
        if(ind>=stones.size()) return false;

        for(int i=ind+1;i<=ind+jump+1 && i<stones.size();i++){ //Note: the less than or equal to symbol
            if(stones[i]>stones[ind]+jump+1) break;
            int jLen=stones[i]-stones[ind]; // the jump length;
            if(jLen==jump || jLen==jump-1 || jLen==jump+1) {
                if(jumper(stones,jLen,i)) return true; // Recursion
            }
        }
        return false;
    }
};

// Then i memozied the solution 
// I am happy i could find out the right idea because this was 2D DP
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        int count=2000;
        int maxJump=1;
        while(count>=0){
            count=count-maxJump;
            maxJump++;
        }
        vector<vector<int>> memo(n,vector<int>(n,-1));
        if(stones[1]!=1) return false;
        int dummy=jumper(stones,1,1,memo);
        return dummy==1? true:false;
    }


    int jumper(vector<int>& stones,int jump,int ind,vector<vector<int>>& memo){
        if(ind==stones.size()-1) return 1;
        if(memo[ind][jump]==1) return 1;
        if(memo[ind][jump]==0) return 0;
        for(int i=ind+1;i<=ind+jump+1 && i<stones.size();i++){ //Note: the less than or equal to symbol
            if(stones[i]>stones[ind]+jump+1) break;
            int jLen=stones[i]-stones[ind]; // the jump length;
            if(jLen==jump || jLen==jump-1 || jLen==jump+1) {
                memo[ind][jump]=jumper(stones,jLen,i,memo);
                if(memo[ind][jump]==1) return 1;
            }
        }
        return 0;
    }
};

// This is one more solution which is DP using unordered_map ( This comes under tabulation itself)
class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int,unordered_set<int>> mp;
        mp[1]={1};
        for(int i=0;i<stones.size();i++){
            for(int jumpSize:mp[stones[i]]){
                mp[stones[i]+jumpSize].insert(jumpSize);
                mp[stones[i]+jumpSize+1].insert(jumpSize+1);
                mp[stones[i]+jumpSize-1].insert(jumpSize-1);
            }
        }   
        return mp[stones.back()].size()!=0;
    }
};

// This is the Tabulation Method

class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        if(stones[1]==1) dp[0][1]=1; // From index 0 i can jump only to length 1
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int diff=stones[i]-stones[j]; 
                if(diff>=n || !dp[j][diff]) continue; 
                // Check if it's a valid jump i.e if it's valid to jump from row j 
                // with a jump lenght of diff then we should make the future jumps as true
                dp[i][diff]=true;
                dp[i][diff-1]=true;
                dp[i][diff+1]=true;
                if(i==n-1) return true;
            }
        }
        return false;
    }
};
#include<bits/stdc++.h>
using namespace std;
// This was my solution apparently it's a DP solution (i didn't know it's DP)
// Time Complexity O(n^2) Space Complexity(O(n)) 
class Solution {
public:
    int jump(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n=nums.size();
        mp[n-1]=0;
        if(n==1) return 0;
        for(int i=n-1;i>=0;i--){
            if(i+nums[i]>=n-1) {
                mp[i]=1;
            }
            else {
                int mini=INT_MAX;
                for(int j=i;j<=i+nums[i];j++){
                    if(mp.count(j)){
                        mini=min(mini,mp[j]);
                    }
                }
                if(mini!=INT_MAX) mp[i]=mini+1;
            }
        }
        return mp[0];
    }
};

// THE OPTiMAL SOLUTION (Striver)
// TIme Complexity O(n) Space Complexity O(1)
class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=0;
        int jump=0;
        while(r<n-1){
            int farthest=r;
            for(int i=l;i<=r;i++){
                farthest=max(i+nums[i],farthest);
            }
            jump++;
            l=r+1;
            r=farthest;
        }
        return jump;
    }
};
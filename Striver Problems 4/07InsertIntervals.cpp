#include<bits/stdc++.h>
using namespace std;

// This was my solution insert and then traverse again to merge it
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        for(int i=0;i<=n;i++){
            if(i==n || intervals[i][0]>newInterval[0]){
                intervals.push_back({0,0});
                int new_n=intervals.size();
                for(int j=new_n-1;j>i;j--){
                    intervals[j]=intervals[j-1];
                }
                intervals[i]=newInterval;
                break;
            }
        }

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][0]<=ans.back()[1] && intervals[i][1]>ans.back()[1]){
                ans.back()[1]=intervals[i][1];
            }
            else if(intervals[i][0]>ans.back()[1]){
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
// This is the optimal one pass solution 
// Time Complexity O(n)
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n=intervals.size();
        int i=0;
        while(i<n && intervals[i][1]<newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }

        while(i<n && newInterval[1]>=intervals[i][0]){
            newInterval[0]=min(newInterval[0],intervals[i][0]);
            newInterval[1]=max(newInterval[1],intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval);
        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};
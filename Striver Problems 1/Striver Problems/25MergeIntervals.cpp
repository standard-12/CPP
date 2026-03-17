#include<bits/stdc++.h>
using namespace std;

// My solution before watching video even this is O(n) but there is better readable solution
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int start=0;
        int end=0;
        int size=intervals.size();
        int i=1;
        vector<vector<int>> ans;
        while(i<size){
            if(intervals[i][0]>intervals[end][1]){
                int x=intervals[start][0];
                int y=intervals[end][1];
                ans.push_back({x,y});
                start=i;
                end=i;
            }
            else if(intervals[i][0]<=intervals[end][1] && intervals[i][1]>=intervals[end][1]){
                end=i;
            }
            i++;
        }
            int x=intervals[start][0];
            int y=intervals[end][1];
            ans.push_back({x,y});
        
        return ans;
    }
};

// The best and short solution 
class Solution2 {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        for(int i=0;i<intervals.size();i++){
            if(ans.empty() || ans.back()[1]<intervals[i][0]){
                ans.push_back(intervals[i]);
            }
            else {
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
            }
        }
        return ans;
    }
};
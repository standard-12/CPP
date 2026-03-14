#include<bits/stdc++.h>
using namespace std;
// Same as last one but return n-count
//Time Complexity O(nlogn)+O(n) Space Complexity O(1);
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),comp);
        int count=0;
        int lastEndTime=INT_MIN;
        for(int i=0;i<n;i++){
            int startTime=intervals[i][0];
            int endTime=intervals[i][1];
            if(startTime>=lastEndTime){
                count++;
                lastEndTime=endTime;
            }
        }
        return n-count;
    }

    static bool comp(const vector<int>& a,const vector<int>& b){
        return a[1]<b[1];
    }
};
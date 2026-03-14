#include<bits/stdc++.h>
using namespace std;

// Yeee i solved it on my own (because this was there in our 4th sem daa subject)
// Time Complexity O(n)+O(nlogn)+O(n)
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int n=start.size();
        vector<pair<int,int>> jobs;
        for(int i=0;i<n;i++) jobs.push_back({start[i],end[i]});
        sort(jobs.begin(),jobs.end(),comp);
        int count=1;
        int lastEndTime=jobs[0].second;
        for(int i=0;i<n;i++){
            int startTime=jobs[i].first;
            int endTime=jobs[i].second;
            if(startTime>lastEndTime){
                count++;
                lastEndTime=endTime;
            }
        }
        
        return count;
    }
    
    static bool comp(const pair<int,int>& a,const pair<int,int>& b){
        if(a.second!=b.second){
            return a.second<b.second;
        }
        return a.first<b.first;
    }
};
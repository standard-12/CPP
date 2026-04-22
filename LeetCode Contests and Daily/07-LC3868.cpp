#include<bits/stdc++.h>
using namespace std;

// I solved this on my own but wasted so much time in this 

class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> first;
        unordered_map<int,int> second;
        unordered_map<int,int> combined;
        int n=nums1.size();
        for(int i=0;i<n;i++){
            first[nums1[i]]++;
            second[nums2[i]]++;
            combined[nums1[i]]++;
            combined[nums2[i]]++;
        }
        for(auto it:combined){
            if(it.second%2!=0) return -1;
        }
        int cost1=0;
        for(auto it:first){
            if(second.count(it.first) && second[it.first]<=first[it.first]) cost1+=(first[it.first]-second[it.first]);
            else if(!second.count(it.first)) cost1+=first[it.first];
        }

        return (cost1+1)/2;
    }
};
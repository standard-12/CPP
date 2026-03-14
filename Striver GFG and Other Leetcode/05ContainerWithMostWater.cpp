#include<bits/stdc++.h>
using namespace std;

// I came up with on my own 
// The idea is if currently there is a container with water the width is the longest possible for that bucket,
// so we can safely move the small pointer because if anything bigger than it exists then it should be in terms of height not width
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int maxarea=0;
        while(i<j){
            int mini=min(height[i],height[j]);
            int area=mini*(j-i);
            maxarea=max(maxarea,area);
            if(mini==height[i]) i++;
            else j--;
        }
        return maxarea;
    }
};
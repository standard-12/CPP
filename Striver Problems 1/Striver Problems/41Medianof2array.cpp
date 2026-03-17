#include<bits/stdc++.h>
using namespace std;

// This is the optimal solution using binary search 
// Time complexity O(log(min(n1,n2)))
// Space Complexity O(1)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        if(n1>n2){
            return findMedianSortedArrays(nums2,nums1);
        }   
        int len=n1+n2;
        int lefthalf=(len/2)+(len%2);
        int beg=0;
        int end=n1;
        while(beg<=end){
            int mid1=beg+(end-beg)/2;
            int mid2=lefthalf-mid1;
            int left1=mid1-1>=0? nums1[mid1-1]:INT_MIN;
            int left2=mid2-1>=0? nums2[mid2-1]:INT_MIN;
            int right1=mid1<n1? nums1[mid1]:INT_MAX;
            int right2=mid2<n2? nums2[mid2]:INT_MAX;

            if(left1<=right2 && left2<=right1){
                if(len%2==1) return (double)max(left1,left2);
                else return (double)(max(left1,left2)+min(right1,right2))/2.0;
            }
            else if(left1>right2){
                end=mid1-1;
            }
            else beg=mid1+1;
        }
        return 0;
    }
};
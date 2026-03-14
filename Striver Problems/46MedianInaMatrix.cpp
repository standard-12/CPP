#include<bits/stdc++.h>
using namespace std;

// This was my solution i had saw the timecomplexity and got a small hint and later i only wrote the code but there is a subtle bug in my code that
// this doesnt work when there is redundant elemetns like for eg 
/*  37 41 48 49 51
    4 9 10 16 22
    28 34 36 37 38
    18 20 28 32 38
    15 17 21 23 27 */
//here answer is 28 but it has appeard 2 times so my cnt will be 14 where as midcnt will be 13 ( i am counting numbers less than or equal to given number)
//but i smartly used pair to detect if element is present or not
// the actual solution doesnt require this check and returns the exact answer because it searches for first element which has cnt>=medcnt (not just equal)(to handle duplicates)
class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        int medcnt=(n*m+1)/2;
        int beg=INT_MAX;
        int end=INT_MIN;
        for(int i=0;i<n;i++){
            beg=min(beg,mat[i][0]);
            end=max(end,mat[i][m-1]);
        }
        while(beg<=end){
            int mid=beg+(end-beg)/2;
            int count=0;
            pair<int,int> p={0,-1};
            bool flag=false;
            for(int i=0;i<n;i++){
                p=countless(mat[i],mid);
                count+=p.second;
                if(p.first){
                    flag=true;
                }
            }
            
            if(count==medcnt && flag) return mid;
            else if(count<medcnt) beg=mid+1;
            else end=mid-1;
        }
        return -1;
    }
    
    pair<int,int> countless(vector<int>& nums,int k){
        int n=nums.size();
        int beg=0;
        int end=n-1;
        int f=0;
        while(beg<=end){
            int mid=beg+(end-beg)/2;
            
            if(nums[mid]<=k){
                beg=mid+1;
            }
            else {
                end=mid-1;
            }
        }
        if(end>=0 && nums[end]==k){
            f=1;
        }
        return {f,end+1};
    }
};


//The working solution

class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        int medcnt=(n*m+1)/2;
        int beg=INT_MAX;
        int end=INT_MIN;
        for(int i=0;i<n;i++){
            beg=min(beg,mat[i][0]);
            end=max(end,mat[i][m-1]);
        }
        while(beg<=end){
            int mid=beg+(end-beg)/2;
            int count=0;

            for(int i=0;i<n;i++){
                count+=countless(mat[i],mid);
            }
            
            if(count<medcnt) beg=mid+1;
            else end=mid-1;
        }
        return beg;
    }
    
    int countless(vector<int>& nums,int k){
        int n=nums.size();
        int beg=0;
        int end=n-1;
        while(beg<=end){
            int mid=beg+(end-beg)/2;
            
            if(nums[mid]<=k){
                beg=mid+1;
            }
            else {
                end=mid-1;
            }
        }

        return end+1;
    }
};

#include<bits/stdc++.h>
using namespace std;

// This is the optimal solution for peak element-2

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int beg=0;
        int end=m-1;
        while(beg<=end){
            int mid=beg+(end-beg)/2;
            int maxi=-1;
            int maxindex;
            for(int i=0;i<n;i++){
                if(mat[i][mid]>maxi){
                    maxi=mat[i][mid];
                    maxindex=i;
                }
            }

            if((mid==0 || maxi>mat[maxindex][mid-1]) && (mid==m-1|| maxi>mat[maxindex][mid+1])){
                return {maxindex,mid};
            } 
            else if((mid==0 || maxi>mat[maxindex][mid-1]) && (mid==m-1|| maxi<mat[maxindex][mid+1])) {
                beg=mid+1;
            }
            else end=mid-1;
        }
        return {-1,-1};
    }
    
};
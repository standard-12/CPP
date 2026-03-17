#include<bits/stdc++.h>
using namespace std;

// This was my solution whose time complexity is logm+logn basically log(mn)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int rowno=-1;
        int beg=0;
        int end=n-1;
        while(beg<=end){
            int mid=beg+(end-beg)/2;
            if(matrix[mid][0]<=target && matrix[mid][m-1]>=target){
                rowno=mid;
                break;
            }
            else if(matrix[mid][0]>target){
                end=mid-1;
            }
            else {
                beg=mid+1;
            }
        }
        if(rowno==-1) return false;
        int beg2=0;
        int end2=m-1;
        while(beg2<=end2){
            int mid2=beg2+(end2-beg2)/2;
            if(matrix[rowno][mid2]==target) return true;
            else if(matrix[rowno][mid2]>target) end2=mid2-1;
            else beg2=mid2+1;
        }
        return false;
    }
};

// Striver solution is 

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int beg=0;
        int end=n*m-1; 
        while(beg<=end){
            int mid=beg+(end-beg)/2;
            int row=mid/m;
            int col=mid%m;
            if(matrix[row][col]== target) return true;
            else if(matrix[row][col]<target) beg=mid+1;
            else end=mid-1;
        }
        return false;
    }
};
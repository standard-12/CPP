#include<bits/stdc++.h>
using namespace std;

// This was Solved in GFG (if wanted to refer)

//Optimal Solution 1 
class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        // code here
        int n=a.size();
        int m=b.size();
        int left=n-1;
        int right=0;
        while(left>=0 && right<m && a[left]>b[right]){
            swap(a[left],b[right]);
            left--;
            right++;
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
    }
};

//Optimal Solution 2 using Gap Method - Shell Sort
class Solution {
    private:
    void swapIfGreater(vector<int>& a,vector<int> &b,int n,int m){
        if(a[n]>b[m]){
            swap(a[n],b[m]);
        }
    }
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        int n=a.size();
        int m=b.size();
        int len=n+m;
        int gap=(len/2)+(len%2);
        while(gap>0){
            int left=0;
            int right=left+gap;
            while(right<len){
                if(left<n && right>=n){
                    swapIfGreater(a,b,left,right-n);
                }
                else if(left>=n){
                    swapIfGreater(b,b,left-n,right-n);
                }
                else {
                    swapIfGreater(a,a,left,right);
                }
                right++;
                left++;
            }
            if(gap==1) break;
            gap=(gap/2)+(gap%2);
        }
        
    }
};

#include<bits/stdc++.h>
using namespace std;

// This is classical pattern for returning no of subsequence with sum K using recursion
class Solution{
    public:    	
    int countSubsequenceWithTargetSum(vector<int>& nums, int k){
    	int n=nums.size();
        return recur(0,0,k,nums,n);
    }
    int recur(int ind,int sum,int k,vector<int>& arr,int n){
        if(sum>k) return 0; // Can be used only if arr contains only positive value
        if(ind==n){
            if(sum==k) return 1;
            else return 0;
        }
        sum+=arr[ind];
        int l=recur(ind+1,sum,k,arr,n);
        sum-=arr[ind];
        int r=recur(ind+1,sum,k,arr,n);
        return l+r;
    }
};

// This is to check if subsequence with sum k exists i.e if a true is found then no more recursion calls are done. This can be used to 
// just print one subsequence where sum is k
class Solution {
  public:
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        bool b=recur(0,0,k,arr,n);
        return b;
    }
    
    bool recur(int ind,int sum,int k,vector<int>& arr,int n){
        if(sum>k) return false;
        if(ind==n){
            if(sum==k) return true;
            else return false;
        }
        if(recur(ind+1,sum,k,arr,n)) return true;
        if(recur(ind+1,sum+arr[ind],k,arr,n)) return true; 
        return false;
    }
};
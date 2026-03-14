#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int inversionCount(vector<int> &arr) {
        // Code Here
        int cnt=0;
        int n=arr.size()-1;
        mergesort(arr,0,n,cnt);
        return cnt;
    }
    
    void merge(vector<int>& nums,int left,int mid,int right,int& cnt){
        int n1=mid-left+1;
        int n2=right-mid;
        
        vector<int> v1(n1),v2(n2);
        for(int i=0;i<n1;i++) v1[i]=nums[left+i];
        for(int j=0;j<n2;j++) v2[j]=nums[mid+1+j];
        int i=0,j=0,k=left;
        while(i<n1 && j<n2){
            if(v1[i]>v2[j]){
                cnt+=n1-i; // The important step 
                nums[k]=v2[j];
                j++;
                k++;
            }
            else {
                nums[k]=v1[i];
                i++;
                k++;
            }
        } 
        while(i<n1){
            nums[k]=v1[i];
            k++;
            i++;
        }
        while(j<n2){
            nums[k]=v2[j];
            j++;
            k++;
        }
    }
    
    void mergesort(vector<int>& nums,int left,int right,int& cnt){
        if(left<right){
            int mid=left+(right-left)/2;
            mergesort(nums,left,mid,cnt);
            mergesort(nums,mid+1,right,cnt);
            merge(nums,left,mid,right,cnt);
        }
    }
};
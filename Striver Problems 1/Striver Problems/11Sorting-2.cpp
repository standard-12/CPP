#include<iostream>
#include<vector>
using namespace std;

// Merge Sort
// Time Complexity - O(nlogn)
// Space Complexity - O(n)
void merge(vector<int>& nums,int left,int mid,int right){
    int n1=mid-left+1;
    int n2=right-mid;

    vector<int> L(n1),R(n2);
    for(int i=0;i<n1;i++) L[i]=nums[left+i];
    for(int j=0;j<n2;j++) R[j]=nums[mid+j+1];

    int i=0,j=0,k=left;

    while(i<n1 && j<n2){
        nums[k++]=(L[i]<=R[j])? L[i++]:R[j++];
    }
    while(i<n1) nums[k++]=L[i++];
    while(j<n2) nums[k++]=R[j++];
}

void mergeSort(vector<int>& nums,int left,int right){
    if(left<right){
        int mid=left+(right-left)/2;//Doing right-left to prevent overflow when both are large numbers
        mergeSort(nums,left,mid);
        mergeSort(nums,mid+1,right);
        merge(nums,left,mid,right);
    }
}
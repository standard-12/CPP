#include<bits/stdc++.h>
using namespace std;
// THIS IS GFG QUESTION NOT LC


class Solution {
  public:
    bool isMaxHeap(int arr[], int n) {
        // Your code goes here
        for(int i=n/2;i>=0;i--){
            if(!(is(arr,n,i))) return false;
         }
         return true;
    }
    
    bool is(int arr[],int n,int i){
        int left=2*i+1;
        int right=2*i+2;
        
        if(arr[left]>arr[i] || arr[right]>arr[i]) return false;
        return true;
    }
};
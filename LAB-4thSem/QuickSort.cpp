#include<iostream>
#include<vector>
#include<algorithm>
using namespace std; 

int partition(vector<int>& arr,int low,int high){
     int pivot=arr[high];
     int i=low-1;

     for(int j=low;j<high;j++){
        if(arr[j]<=pivot){
            ++i;
            swap(arr[i],arr[j]);
        }
     }
     swap(arr[i+1],arr[high]);
     return i+1;
}

void quicksort(vector<int>& arr,int low,int high){
    if(low<high){
        int pivotindex=partition(arr,low,high);
        quicksort(arr,low,pivotindex-1);
        quicksort(arr,pivotindex+1,high);
    }
}
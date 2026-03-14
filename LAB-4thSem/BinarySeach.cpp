#include<iostream>
#include<chrono>
using namespace std;

int BinarySearch(int arr[],int left,int right,int target){
    if(left>right)
        return -1;
    int mid=left+(right-left)/2;

    if(arr[mid]==target)
        return mid;
    else if(arr[mid]<target)
        return BinarySearch(arr,mid+1,right,target);
    else
        return BinarySearch(arr,left,mid-1,target);
}

int BinarySearch_iterative(int arr[],int size,int target){
    int left=0;
    int right=size-1;
    
    while(left<=right){
        int mid=left+(right-left)/2;

        if(arr[mid]==target)
            return mid;
        else if(target<arr[mid])
            right=mid-1;
        else
            left=mid+1;
    }
    return -1;
}
int linear_search(int arr[],int size,int target){
    for(int i=0;i<size;i++){
        if(arr[i]==target) return i;
    }
    return -1;
}

int main(){
    int arr[10000];
    for(int i=1;i<=10000;i++){
        arr[i-1]=i;
    }
    int key=9999;
    int index=-1;
    auto start=std::chrono::high_resolution_clock::now();
    for(int i=0;i<100;i++){
     index=linear_search(arr,10000,key);
    }
    auto end=std::chrono::high_resolution_clock::now();
    std::chrono::microseconds elapsed= std::chrono::duration_cast<std::chrono::microseconds>(end-start);
    cout<<"Index is: "<<index<<endl;
    cout<<"elapsed time is :"<<elapsed.count();
    return 1;
}
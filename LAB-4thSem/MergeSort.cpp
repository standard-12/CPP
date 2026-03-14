#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& v1,int left,int mid,int right) {
    int n1=mid-left +1;
    int n2=right-mid;

    vector<int> L(n1),R(n2);
    for(int i=0;i<n1;i++) L[i]=v1[left+i];
    for(int j=0;j<n2;j++) R[j]=v1[mid+j+1];

    int i=0,j=0,k=left;
    while(i<n1 && j<n2){
        v1[k++]= (L[i]<=R[j])? L[i++]:R[j++];
    }
    while(i<n1) v1[k++]=L[i++];
    while(j<n2) v1[k++]=R[j++];

}

void mergesort(vector<int>& arr,int left ,int right){
    if(left>= right) return;

    int mid=left+(right-left)/2;  //Doing right-left to prevent overflow when both are large numbers
    mergesort(arr,left,mid);
    mergesort(arr,mid+1,right);
    merge(arr,left,mid,right);
}

int main() {
    vector<int> arr;
    int n;
    cout<<"Enter array size :";
    cin>>n;

    arr.resize(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<endl;

    mergesort(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

// There is no advantage of these its just for eductaional purpose and learning recursion
//Time Complexity O(n^2)
//Space Complexity O(n)

void recursive_buublesort(vector<int>& nums,int size){
    if(size==1) return ;
    for(int i=0;i<size-1;i++){
        if(nums[i]>nums[i+1]){
            swap(nums[i],nums[i+1]);
        }
    }
    recursive_buublesort(nums,size-1);
}

void recursive_insertionsort(vector<int>& nums ,int i){
    if(i==nums.size()) return;
    int j=i;
    while(j>0 && nums[j-1]>nums[j]){
        swap(nums[j-1],nums[j]);
        j--;
    }
    recursive_insertionsort(nums,i+1);
}

void recursive_selectionsort(vector<int>& nums,int i){
    if(i==nums.size()) return;
    int min=i;
    for(int j=i+1;j<nums.size();j++){
        if(nums[j]<nums[min]){
            min=j;
        }
    }
    if(min!=i)
        swap(nums[i],nums[min]);
    recursive_selectionsort(nums,i+1);
}

int main() {
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    // recursive_buublesort(nums,n);
    // recursive_insertionsort(nums,0);
    recursive_selectionsort(nums,0);
    for(int j=0;j<n;j++){
        cout<<nums[j]<<" ";
    }
    return 0;
}
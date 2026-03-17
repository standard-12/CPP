#include<iostream>
#include<vector>
using namespace std;

void selectionSort(vector<int>& nums){   // Selecting the minimum
    int size=nums.size();
    for(int i=0;i<size;i++){
        int min=i;
        for(int j=i+1;j<size;j++){  // Time Complexity O(N^2) 
            if(nums[j]<nums[min]){
                min=j;
            }
        }
        if(min!=i)
            swap(nums[i],nums[min]);
    }
}

void bubbleSort(vector<int>& nums){ // Push the maximum to last 
    int size=nums.size();// We can use flag to break from the loop if array is already sorted so Best case O(N)
    for(int i=0;i<size;i++){
        for(int j=0;j<size-i-1;j++){
            if(nums[j]>nums[j+1]){  //Time Complexity o(N^2)
                swap(nums[j],nums[j+1]);
            }
        }
    }
}

void insertionSort(vector<int>& nums){ // Take a element and place it in its right position
    int size=nums.size();          // Best case-O(N)
    for(int i=0;i<size;i++){
        int j=i;
        while(j>0 && nums[j-1]>nums[j]){ //Time Complexity O(N^2) 
            swap(nums[j-1],nums[j]); 
            j--;
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<endl;
    // selectionSort(nums);
    // bubbleSort(nums);
    insertionSort(nums);
    for(int i=0;i<n;i++){
        cout<<nums[i];
    }

}
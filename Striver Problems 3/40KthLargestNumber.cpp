#include<bits/stdc++.h>
using namespace std;

// Many solutions exist for this
// My solution-1 Time Complexity O(NlogN) Space COmplexity O(1)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        return nums[n-k];
    }
};
// My Solution-2 Time Complexity O(N+KlogN) Space Complexity O(1)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=n/2;i>=0;i--){
            heapify(nums,i);  // O(n)
        }
        while(k>1){
            deleteFromHeap(nums); // O(KlogN)
            k--;
        }
        return nums[0];
    }

    void deleteFromHeap(vector<int>& nums){
        int n=nums.size();
        if(n==0) return;
        nums[0]=nums[n-1];
        nums.pop_back();
        heapify(nums,0);
    }

    void heapify(vector<int>& nums,int i){
        int n=nums.size();
        int largest=i;
        int left=2*i+1;
        int right=2*i+2;

        if(left<n && nums[largest]<nums[left]){
            largest=left;
        }
        if(right<n && nums[largest]<nums[right]){
            largest=right;
        }
        if(largest!=i){
            swap(nums[i],nums[largest]);
            heapify(nums,largest);
        }
    }
};

// QuickSelect solution 
// Mostly O(n) But O(n^2) in worst case so TLE occurs
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int target = n - k;
        int l = 0, r = n - 1;

        // iterative quickselect
        while (l <= r) {
            int p = partition(nums, l, r);   // pivot final index
            if (p == target) return nums[p];
            else if (p < target) l = p + 1;
            else r = p - 1;
        }
        return -1;
    }

int partition(vector<int>& a, int l, int r) {
        // random pivot to avoid worst-case
        int pivotIndex = l + rand() % (r - l + 1);
        swap(a[pivotIndex], a[r]);
        int pivot = a[r];

        int pIndex = l; // place for next element <= pivot
        for (int i = l; i < r; ++i) {
            if (a[i] <= pivot) {
                swap(a[i], a[pIndex]);
                ++pIndex;
            }
        }
        swap(a[pIndex], a[r]);
        return pIndex;
    }
};
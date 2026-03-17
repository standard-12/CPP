#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        mergesort(nums,0,n-1,cnt);
        return cnt;
    }

    void merge(vector<int>& nums, int left, int mid, int right, int& cnt) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<int> v1(n1), v2(n2);
        for (int i = 0; i < n1; i++)
            v1[i] = nums[left + i];
        for (int j = 0; j < n2; j++)
            v2[j] = nums[mid + 1 + j];
        int i = 0, j = 0, k = left;
        cnt+=countpairs(v1,v2);
        while (i < n1 && j < n2) {
            if (v1[i] >v2[j]) {
                nums[k] = v2[j];
                j++;
                k++;
            } else {
                nums[k] = v1[i];
                i++;
                k++;
            }
        }
        while (i < n1) {
            nums[k] = v1[i];
            k++;
            i++;
        }
        while (j < n2) {
            nums[k] = v2[j];
            j++;
            k++;
        }
    }

    void mergesort(vector<int>& nums, int left, int right, int& cnt) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergesort(nums, left, mid, cnt);
            mergesort(nums, mid + 1, right, cnt);
            merge(nums, left, mid, right, cnt);
        }
    }

    int countpairs(vector<int>& v1,vector<int>& v2){
        int n1=v1.size();
        int n2=v2.size();
        int cnt=0;
        int i=0,j=0;
        while(i<n1){
            while(j<n2 && (long long)v1[i]>2LL*v2[j]){
                
                j++;
            }
            cnt=cnt+j;
            i++;
        }
   
        return cnt;
    }
};
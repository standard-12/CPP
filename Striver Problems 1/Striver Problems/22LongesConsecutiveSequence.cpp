#include<vector>
#include<iostream>
#include<unordered_set>
using namespace std;

// Time Complexity O(n)+o(2n)
int longest(vector<int>& nums){
    unordered_set<int> st(nums.begin(), nums.end()); //Time COmplexity O(n)
    int maxcnt = 0;

    for (int num : nums) {  //Time Complexity O(2n)
        if (st.find(num - 1) != st.end()) continue; // If it is not the first number of an sequence

        int current = num;
        int count = 1;

        while (st.find(current + 1) != st.end()) {
            current++;
            count++;
        }

        maxcnt = max(maxcnt, count);
    }

    return maxcnt;
}

// Brute for or may be better solution not the optimal
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int maxcnt=0;
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        for(int s : st){
            int count=0;
            if(st.count(s-1)) continue;
            while(st.count(s)){
                count++;
                s=s+1;
            }
            maxcnt=max(maxcnt,count);
        }
        return maxcnt;
    }
};

int main() {
    vector<int> nums={100,5,200,6,7,2,4,3,500};
    cout<<longest(nums);
    return 0;
}

/*
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        sort(nums.begin(), nums.end());
        int maxi = 1;
        int count = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) continue; // skip duplicates
            if (nums[i] == nums[i - 1] + 1) {
                count++;
            } else {
                count = 1;
            }
            maxi = max(maxi, count);
        }

        return maxi;
    }
};

*/ 
/* This is the better solution which i had found . But above is the best solution  */
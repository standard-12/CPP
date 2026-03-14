#include<bits/stdc++.h>
using namespace std;

// I could solve this on my own 
// First i thought of using unordered_set to check any index can reach a good index (if it can insert it) and at the end 
// check if the first index can reach any good index by checking 0+nums[i]
// THIS IS NOT THE RIGHT ANSWER this fails for [2,0] [2,5,0,0,0] etc
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> st; 
        st.insert(n-1);
        for(int i=n-2;i>=1;i--){
            if(st.count(i+nums[i])){
                st.insert(i);
            }
        }
        return st.count(0+nums[0])? true:false;
    }
};

// Then i realized we should use stack and check <= st.top() and put it into stack
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        stack<int> st;
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            if(i+nums[i]>=st.top()){
                st.push(i);
            }
        }
        return nums[0]>=st.top()? true:false;
    }
};

// But then i realised even stack is not needed since we are only comparing the st.top()
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int comp=n-1;
        for(int i=n-2;i>=0;i--){
            if(i+nums[i]>=comp){
                comp=i;
            }
        }
        return nums[0]>=comp? true:false;
    }
};

// The Striver solution which goes from start to end
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int farthest=0;
        for(int i=0;i<n;i++){
            if(i>farthest) return false;
            farthest=max(farthest,i+nums[i]);
        }
        return true;
    }
};

// Simply wrote recursive solution to see if i remember recursion
class Solution {
public:
    bool canJump(vector<int>& nums) {
        return recur(nums,0);
    }

    bool recur(vector<int>& nums,int index){
        int n=nums.size();
        if(index>=n-1) return true;
        for(int i=index+1;i<=index+nums[index];i++){
            if(nums[i]!=0){
                if(recur(nums,i)) return true;
            }
        }
        return false;
    }
};

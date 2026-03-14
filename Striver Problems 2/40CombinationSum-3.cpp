#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        recur(1,n,k,temp,ans);
        return ans;
    }
    void recur(int dig,int sum,int k,vector<int>& temp,vector<vector<int>>& ans){
        int n=temp.size();
        if(n==k && sum==0){
            ans.push_back(temp);
            return;
        }
        if(n>=k || dig>9 || sum<0) return;
        for(int i=dig;i<10;i++){
            temp.push_back(i);
            recur(i+1,sum-i,k,temp,ans); // i had written sum-dig it should be sum-i since first digit can be anything from 1 to 10
            temp.pop_back();
        }
    }
};

// I did everything write in above code but i could have pruned it better 
// the below code does all the pruning possible 

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        recur(1, n, k, temp, ans);
        return ans;
    }

private:
    void recur(int dig, int sum, int k, vector<int>& temp, vector<vector<int>>& ans) {
        if (sum == 0 && (int)temp.size() == k) {
            ans.push_back(temp);
            return;
        }
        if ((int)temp.size() >= k || dig > 9 || sum < 0) return;

        // remaining numbers available from dig..9 inclusive
        int remainingCount = 10 - dig;
        if ((int)temp.size() + remainingCount < k) return; // can't reach k distinct digits

        for (int i = dig; i <= 9; ++i) {
            if (i > sum) break; // pruning: numbers are increasing, no need to continue
            temp.push_back(i);
            recur(i + 1, sum - i, k, temp, ans);
            temp.pop_back();
        }
    }
};

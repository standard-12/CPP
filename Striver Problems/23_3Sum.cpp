#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threesum1(vector<int>& nums){
    set<vector<int>> ans;
    for(int i=0;i<nums.size();i++){
        set<int> hashset;
        for(int j=i+1;j<nums.size();j++){
            int third=-(nums[i]+nums[j]);
            if(hashset.find(third) !=hashset.end()){
                vector<int> temp={nums[i],nums[j],third};
                sort(temp.begin(),temp.end());
                ans.insert(temp);
            }
            hashset.insert(nums[j]);
        }
    }
    vector<vector<int>> finalans(ans.begin(),ans.end());
    return finalans;
}


vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(),nums.end());
       vector<vector<int>> ans;
   
       for(int i=0;i<nums.size();i++){
        if(i>0 && nums[i-1]==nums[i]) continue;
        int left=i+1;
        int right=nums.size()-1;
        while(left<right){

            int sum=nums[left]+nums[right]+nums[i];
             if(sum==0){
                ans.push_back({nums[i],nums[left],nums[right]});
                do{
                    left++;
                }while(nums[left-1]==nums[left] && left<right);
                do{
                    right--;
                }while(nums[right+1]==nums[right]&& left<right);
                }
            else if(sum<0){
                    left++;
                }
            else {
                    right--;
                }
            }
        }
        vector<vector<int>> final(ans.begin(),ans.end());
        return final;
    }
// Striver solution same as above but with better readability
vector<vector<int>> triplet(int n, vector<int> &arr) {
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        //remove duplicates:
        if (i != 0 && arr[i] == arr[i - 1]) continue;

        //moving 2 pointers:
        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < 0) {
                j++;
            }
            else if (sum > 0) {
                k--;
            }
            else {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                //skip the duplicates:
                while (j < k && arr[j] == arr[j - 1]) j++;
                while (j < k && arr[k] == arr[k + 1]) k--;
            }
        }
    }
    return ans;
}

int main() {
    vector<int> nums={-4,1,2,-1,0,-1,-1,2,3,4,-1,-1,2};
    vector<vector<int>> ans=threeSum(nums);
    for(vector<int> i :ans){
        for(int j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
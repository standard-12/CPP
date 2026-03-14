#include<bits/stdc++.h>
using namespace std;
// This is a nice solution since there is 2 condition 
// We can use pair also for that we have to write custom hash function see solnt 2
class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        int n=nums.size();
        unordered_map<string,int> mp;
        int sum=0,balanced=0,maxLen=0;
        mp["0_0"]=-1;
        for(int i=0;i<n;i++){
            sum=sum^nums[i];
            if(nums[i]%2==1) balanced++;
            else balanced--;
            string str=to_string(sum)+"_"+to_string(balanced);
            if(mp.count(str)){
                int index=mp[str];
                maxLen=max(maxLen,i-index);
            }
            else
                mp[str]=i;
        } 
        return maxLen;
    }
};

class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {

        // Custom hash function
        struct pairHash{
            size_t operator()(const pair<int,int>& p)
                const noexcept{
                    return (static_cast<uint64_t>(static_cast<uint32_t>(p.first))<<32)^static_cast<uint32_t>(p.second);
            }
        };

        int n=nums.size();
        unordered_map<pair<int,int>,int,pairHash> mp;
        int sum=0,balanced=0,maxLen=0;
        mp[{0,0}]=-1;
        for(int i=0;i<n;i++){
            sum=sum^nums[i];
            if(nums[i]%2==1) balanced++;
            else balanced--;
            pair<int,int> p={sum,balanced};
            if(mp.count(p)){
                int index=mp[p];
                maxLen=max(maxLen,i-index);
            }
            else
                mp[{sum,balanced}]=i;
        } 
        return maxLen;
    }
};
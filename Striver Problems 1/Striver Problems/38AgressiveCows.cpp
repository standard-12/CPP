#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& stalls, int k) {
        int n=stalls.size();
        sort(stalls.begin(),stalls.end());
        int ans=0;
        int beg=1;
        int end=*(max_element(stalls.begin(),stalls.end()));
        while(beg<=end){
            int mid=beg+(end-beg/2);
            bool b=isPossible(stalls,mid,k);
            
            if(b){
                ans=mid;
                beg=mid+1;
            }
            else {
                end=mid-1;
            }
        }
        return ans;
    }
    
    bool isPossible(vector<int>& stalls,int mid,int k){
        int n=stalls.size();
        int comp=stalls[0];
        int count=0;
        for(int i=1;i<n;i++){
            if(stalls[i]-comp>=k){
                count++;
                comp=stalls[i];
            }
            if(count==k){
                return true;
            }
        }
        return false;
    } 
    
};

int main() {
    Solution S;
    vector<int> stalls={1,2,3,4,7};
    int k=3;
    cout<<S.maxDistance(stalls,k);
    return 0;
}
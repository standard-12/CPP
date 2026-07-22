#include<bits/stdc++.h>
using namespace std;

// New Concept - Differential Array

class Solution {
public:
    int minLights(vector<int>& lights) {
        int n=lights.size();
        vector<int> pref(n,0);
        for(int i=0;i<n;i++){
            if(lights[i]!=0){
                int bulbPower=lights[i];
                int l=max(0,i-bulbPower);
                int r=min(n-1,i+bulbPower);
                pref[l]+=1;
                if(r+1<n) pref[r+1]-=1;
            }
        }

        for(int i=1;i<n;i++){
            pref[i]+=pref[i-1];
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(pref[i]==0){
                ans+=1;
                i+=2;
            }
        }
        return ans;
    }
};
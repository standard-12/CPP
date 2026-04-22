#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int binaryToDecimal(string &b) {
        int n=b.size();
        int pow2=1;
        int ans=0;
        for(int i=n-1;i>=0;i--){
            if(b[i]=='1') ans+=pow2;
            pow2*=2;
        }
        return ans;
    }
};
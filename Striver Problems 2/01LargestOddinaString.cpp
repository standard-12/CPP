#include<bits/stdc++.h>
using namespace std;

// this was the worst possible solution that also not working properly should see why 
class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size();
        int start=0;
        int len=0;
        int max=INT_MIN;
        for(int i=n-1;i>=0;i--){
            long long dig=1;
            long long temp=0;
            for(int j=i;j>=0;j--){
                long long value=num[j]-48;
                temp+=value*dig;
                dig=dig*10;
                if(temp>max && temp%2==1){
                    max=temp;
                    len=i-j+1;
                    start=j;
                }
            }
        }
        string ans=num.substr(start,len);
        return ans;
    }
};
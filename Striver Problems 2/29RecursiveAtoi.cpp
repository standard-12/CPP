#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int n=s.size();
        while(i<n && s[i]==' ') i++;
        int sign=1;
        if(s[i]=='+' || s[i]=='-') {
            if(s[i]=='-') sign=-1;
            i++;
        }
        long long num=0;
        return recursiveAtoi(s,i,sign,num);
    }

    int recursiveAtoi(string s,int i,int sign,long long num){
        if(i>=s.size() || !isdigit(s[i])) {
            return num*sign;
        }
        num=num*10 + (s[i]-'0');
        if(num*sign > INT_MAX) return INT_MAX;
        if(num*sign < INT_MIN) return INT_MIN;
        return recursiveAtoi(s,i+1,sign,num);
    }
};
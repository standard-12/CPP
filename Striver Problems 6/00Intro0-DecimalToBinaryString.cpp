#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string decToBinary(int n) {
        // code here
        string s="";
        while(n>0){
           int m=n%2;
           n=n/2;
           if(m==1) s.append("1");
           else s.append("0");
        }
        reverse(s.begin(),s.end());
        return s;
    }
};
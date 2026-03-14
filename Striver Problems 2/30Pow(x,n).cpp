#include<bits/stdc++.h>
using namespace std;

//binary exponentiation by dividing n/2;
// This is the recursive version with time complexity O(log n)
class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long nn=n; // convert to long long to handle edge case when n=INT_MIN since we can not do it positive with int
        if(nn<0) nn=-1*nn;
        ans=fastpow(x,nn);
        if(n<0) return (double)1.0/ans;
        else return ans;
    }
    double fastpow(double x,long long n){
        if(n==0) return 1;

        if(n%2){
            return (double)x*fastpow(x,n-1);
        }
        else{
            return fastpow(x*x,n/2);
        }
    }
};

//Iterative method
class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long nn=n;
        if(nn<0) nn=-1*nn;
        while(nn>0){
            if(nn%2){
                ans=ans*x;
                nn=nn-1;
            }
            else {
                x=x*x;
                nn=nn/2;
            }
        }
        if(n<0) return (double)1.0/ans;
        else return ans;
    }
};
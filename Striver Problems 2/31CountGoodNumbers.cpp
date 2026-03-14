#include<bits/stdc++.h>
using namespace std;


// Uses Binary Exponential method to calculate power 
// Uses permutation of numbers formula (with repeatation) Even Digits=0,2,4,6,8 Prime Digits=2,3,5,7

class Solution {
public:
    int countGoodNumbers(long long n) {
        long long even=(n+1)/2;
        long long prime=n-even;

        long long evenDigits=fastpow(5,even);
        long long primeDigits=fastpow(4,prime);
        const int MOD=1e9+7;
        evenDigits=evenDigits%MOD;
        primeDigits=primeDigits%MOD;
        int ans = (evenDigits*primeDigits) % MOD;
        return ans;
    }
    long long fastpow(long long x,long long n){
        long long ans=1;
        int MOD=1e9+7;
        while(n){
            if(n%2){
                ans=(ans*x)%MOD;
                n=n-1;
            }
            else {
                x=(x*x)%MOD;
                n=n/2;
            }
        }
        return ans;
    }
};


#include<bits/stdc++.h>
using namespace std;

// One of the nicest solution 
// Question is count commas in a range [1,n] with 1<=n<=1e15
class Solution {
public:
    long long countCommas(long long n) {
        long long p=1000;
        long long ans=0;
        while(n>=p){
            ans+=n-p+1;
            p=p*1000;
        }
        return ans;
    }
};

// If no is 123,456,789 
// The first iteration counts the first comma
// Like 123,456,789-1000+1 => 123,455,790 comma's (the first comma second comma not counted yet)
// Second comma no is 123,456,789-1,000,000 + 1 => 122,456,790
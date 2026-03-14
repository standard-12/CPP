#include<bits/stdc++.h>
using namespace std;

// I came up with this on my own this was a nice question LC 1423

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int l=n-1,r=n-1;
        int sum=0,maxSum=0; 
        while(r>n-k-1){   // Initializing  a window of size k form back side
            sum+=cardPoints[r];
            maxSum=max(maxSum,sum);
            r--;
        }
        r++;
    
        while(r<n){  // Moving the window until end i.e at the end window will be from front side
            sum=sum-cardPoints[r];
            r++;
            l=(l+1)%n;
            sum=sum+cardPoints[l];
            maxSum=max(maxSum,sum);
        }
        return maxSum;
    }
};
#include<bits/stdc++.h>
using namespace std;

// This was my solution Time Complexity O(3n) Space O(n)
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> candies(n,1);
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                candies[i]=candies[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                if(candies[i]<=candies[i+1]){
                    candies[i]=candies[i+1]+1;
                }
            }

        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=candies[i];
        }
        return sum;
    }

};

// This is the optimal solution for this problem Time O(n) Space O(1)
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int i=1;
        int res=1; // For index 0 candy
        while(i<n){
            if(ratings[i]==ratings[i-1]){
                i++;
                res++;
                continue;
            }
            int peak=1;
            while(i<n && ratings[i]>ratings[i-1]){
                peak++;
                i++;
                res+=peak;
            }
            int down=1;
            while(i<n && ratings[i]<ratings[i-1]){
                res+=down;
                i++;
                down++;
            }
            if(down>peak){
                res+=(down-peak);
            }
        }
        return res;
    }
};
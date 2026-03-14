#include<bits/stdc++.h>
using namespace std;

//LeetCode q.no=2965
// I solved this myself without any help using XOR and HashMap
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int size=grid.size();
        int repeated;
        int missing=0;
        int cnt=1;
        unordered_map<int,int> mp; 
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(mp.find(grid[i][j])!=mp.end()){
                    repeated=grid[i][j];
                }
                missing^=grid[i][j]^cnt;
                mp[grid[i][j]];
                cnt++;
            }
        }
        missing^=repeated;
        return {repeated,missing};
    }
};

// Optimal Solution 1 using Maths

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int size=n*n;
        long long S= (1LL*size*(size+1))/2; //1LL is the long long representation of 1 
        long long S2=(1LL*size*(size+1)*(2*size+1))/6;
        long long sum=0,sum2=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sum+=grid[i][j];
                sum2+=(long long)grid[i][j]*grid[i][j];
            }
        }
        long long val1=sum-S; // x-y
        long long val2=sum2-S2; // x^2-y^2 
        val2=val2/val1; // x^2-y^2=(x+y)(x-y) so we already have the value of x-y
        long long x=(val1+val2)/2; // solving x+y =val1 and x-y=val2
        long long y=val2-x;
        return {(int)x,(int)y};

    }
};

// Otpimal Solution -2 using xor 

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int N = n * n;

        int xr = 0;

        // Step 1: XOR all elements in grid and numbers from 1 to N
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                xr ^= grid[i][j];
            }
        }
        for (int i = 1; i <= N; i++) {
            xr ^= i;
        }

        // Step 2: Find a set bit (rightmost)
        int bitNo = 0;
        while ((xr & (1 << bitNo)) == 0) {
            bitNo++;
        }

        int x = 0, y = 0;
        // Partition into two sets based on bitNo
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((grid[i][j] & (1 << bitNo)) != 0)
                    x ^= grid[i][j];
                else
                    y ^= grid[i][j];
            }
        }

        for (int i = 1; i <= N; i++) {
            if ((i & (1 << bitNo)) != 0)
                x ^= i;
            else
                y ^= i;
        }

        // Step 3: Determine which is missing and which is repeated
        int countX = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == x)
                    countX++;
            }
        }

        if (countX == 2) {
            return {x, y};  // x is repeated
        } else {
            return {y, x};  // y is repeated
        }
    }
};

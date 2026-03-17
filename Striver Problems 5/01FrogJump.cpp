#include<bits/stdc++.h>
using namespace std;

// This is from LC and Strivers Frog jump is diff(it's the next que)
// I wrote this recursion on my own so happy about it 
// I knew this would give tle since constraint is n<=2000 
// 
class Solution {
public:
    bool canCross(vector<int>& stones) {
        if(stones[1]!=1) return false;
        return jumper(stones,1,1);
    }

    bool jumper(vector<int>& stones,int jump,int ind){
        if(ind==stones.size()-1) return true;
        if(ind>=stones.size()) return false;

        for(int i=ind+1;i<=ind+jump+1 && i<stones.size();i++){ //Note: the less than or equal to symbol
            if(stones[i]>stones[ind]+jump+1) break;
            int jLen=stones[i]-stones[ind]; // the jump length;
            if(jLen==jump || jLen==jump-1 || jLen==jump+1) {
                if(jumper(stones,jLen,i)) return true; // Recursion
            }
        }
        return false;
    }
};
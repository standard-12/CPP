#include<bits/stdc++.h>
using namespace std;

// I wrote this solution on my own without any help this was optimal but a minor optmization could be donoe by not erasing instead checking if 
// it was appearing before before i or after i
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int i=0;
        int j=0;
        
        int maxi=0;
        unordered_map<char,int> mp;
        while(i<n && j<n){
            while(j<n && !mp.count(s[j])){
                mp[s[j]]=j;
                maxi=max(maxi,j-i+1);
                j++;
            }
            int jindex=mp[s[j]];
            while(i<n && i<=jindex){
                mp.erase(s[i]);
                i++;
            }
        }
        return maxi;
    }
};

class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i = 0, j = 0;
        int maxi = 0;
        unordered_map<char,int> mp; // char -> last index

        while (j < n) {
            if (mp.count(s[j]) && mp[s[j]] >= i) {
                // duplicate inside window, move i just after previous index
                i = mp[s[j]] + 1;
            }
            mp[s[j]] = j; // update last seen index
            maxi = max(maxi, j - i + 1);
            j++;
        }
        return maxi;
    }
};

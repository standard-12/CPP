#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        bool b=isSorted(s);
        if(b) return 0;
        if(n==2) return -1;

        char min='z';
        char max='a';
        for(int i=0;i<n;i++){
            if(s[i]<min) min=s[i];
            if(s[i]>max) max=s[i];
        }
        if(min==s[0] || max==s[n-1]) return 1; // We can sort the other n-1 string 

        if(min==s[n-1] && max==s[0]){
            bool isThree=0;
            for(int i=1;i<n-1;i++){
                if(min==s[i] || max==s[i]) return 2;
            }
            return 3; // If there is no duplicate then min 3 operations needed
        }
        return 2;
    }

    bool isSorted(string& s){
        int n=s.size();
        for(int i=1;i<n;i++){
            if(s[i]<s[i-1]) return false;
        }
        return true;
    }
};
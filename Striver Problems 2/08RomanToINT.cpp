#include<bits/stdc++.h>
using namespace std;

// This was my solution it is optimal in terms of complexities but very long 
// see below for shorter solution with hashmap
class Solution {
public:
    int romanToInt(string s) {
        int n=s.size();
        int temp=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='I'){
                temp+=1;
            }
            else if(s[i]=='V'){
                if(i-1>=0 && s[i-1]=='I') {
                    temp+=4;
                    i--;
                }
                else
                temp+=5;
            }
            else if(s[i]=='X'){
                if(i-1>=0 && s[i-1]=='I') {
                    temp+=9;
                    i--;
                }
                else
                temp+=10;                
            }
            else if(s[i]=='L'){
                if(i-1>=0 && s[i-1]=='X') {
                    temp+=40;
                    i--;
                }
                else
                temp+=50;                    
            }
            else if(s[i]=='C'){
                if(i-1>=0 && s[i-1]=='X') {
                    temp+=90;
                    i--;
                }
                else
                temp+=100;                    
            }
            else if(s[i]=='D'){
                if(i-1>=0 && s[i-1]=='C') {
                    temp+=400;
                    i--;
                }
                else
                temp+=500;                    
            }
            else if(s[i]=='M'){
                if(i-1>=0 && s[i-1]=='C') {
                    temp+=900;
                    i--;
                }
                else
                temp+=1000;                    
            }
        }
        return temp;
    }
};

// Uses maps and subtracts value if a lower value is found before a larger value
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> val = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int n = s.size();
        int ans = 0, prev = 0;

        for (int i = n - 1; i >= 0; i--) {
            int cur = val[s[i]];
            if (cur < prev) ans -= cur;   // subtractive case
            else ans += cur;
            prev = cur;
        }
        return ans;
    }
};

#include<bits/stdc++.h>
using namespace std;
// LC 12
// This is the optimal solution 
class Solution {
public:
    string intToRoman(int num) {
        const vector<pair<int,string>> vals {{1000,"M"},{900,"CM"},{500,"D"},{400,"CD"},{100,"C"},{90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
            {5, "V"},    {4, "IV"},   {1, "I"}};
        
    
    string res;
    for (const auto& it : vals){
        while (num>=it.first){
        num-=it.first;
        res+=it.second;
         }
    }
    return res;
}
};

// This was my solution

class Solution {
public:
    
    string intToRoman(int num) {
        unordered_map<int,vector<char>> mp;
        mp[3]={'M'};
        mp[2]={'C','D','M'};
        mp[1]={'X','L','C'};
        mp[0]={'I','V','X'};
        string s;
        int cnt=0;
        int copy=num;
        while(copy>0){
            int dig=copy%10;
            copy=copy/10;
            vector<char> v=mp[cnt];
            if(dig==4){
                s.push_back(v[1]);
                s.push_back(v[0]);
            }
            else if(dig==9){
                s.push_back(v[2]);
                s.push_back(v[0]);
            }
            else {
                bool b=false;
                if(dig>=5) {
                    dig=dig-5;
                    b=true;
                }
                while(dig>0) {
                    s.push_back(v[0]);
                    dig--;
                }
                if(b) s.push_back(v[1]);
            }
            cnt++;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};
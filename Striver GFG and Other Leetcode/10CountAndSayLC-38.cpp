#include<bits/stdc++.h>
using namespace std;

// This was a nice question i liked it that's why i saved it here 
// I did it on myself See q.no 38 in LC for more info

class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        return RLE(countAndSay(n-1));
    }

    string RLE(string str){
        int n=str.size();
        int i=0;
        string ans="";
        str+='*'; // Simply adding it for convinience in comparing i and i+1;
        while(i<n){
            int cnt=1;
            while(str[i]==str[i+1]){
                cnt++;
                i++;
            }
            string freq="";
            while(cnt>0){
                int dig=cnt%10;
                cnt=cnt/10;
                freq+='0'+dig;
            }
            reverse(freq.begin(),freq.end());
            if(freq.size()>0) {
                ans+=freq;
                ans+=str[i];
            }
            i++;
        }
        cout<<ans;
        return ans;
    }


};
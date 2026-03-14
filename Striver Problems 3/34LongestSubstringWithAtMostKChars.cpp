#include<bits/stdc++.h>
using namespace std;

// This is one of the approach
class Solution {
public:
    int kDistinctChar(string& s, int k) {
        //your code goes here
        int n=s.size();
        vector<int> vec(26,-1);
        int i=0;
        int dist=0;
        int len=0;
        for(int j=0;j<n;j++){
            if(vec[s[j]-'a']==-1) dist++;
            vec[s[j]-'a']=j;
            if(dist>k){
                int minIndex=getMin(vec);
                i=vec[minIndex]+1;
                vec[minIndex]=-1;
                dist--;
            }
            len=max(len,j-i+1);
        }
        return len;
    }

    int getMin(vector<int>& vec){
        int minIndex=-1;
        int mini=INT_MAX;
        for(int i=0;i<26;i++){
            if(vec[i]==-1) continue;
            if(vec[i]<mini){
                minIndex=i;
                mini=vec[i];
            }
        }
        return minIndex;
    }
};

// Ooptimal By strinver 

class Solution {
    public:
        int LongestSubstringAtMostK(string s,int k){
            int n=s.size();
            unordered_map<char,int> freq;
            int l=0,r=0,len=0;
            while(r<n){
                freq[s[r]]++;
                while(freq.size()>k){ // Replace while by if for O(n)
                    freq[s[l]]--;
                    if(freq[s[l]]==0) freq.erase(s[l]);
                    l++;
                }
                if(freq.size()<=k){
                    len=max(len,r-l+1);
                }
                r++;
            }
            return len;
        }
};
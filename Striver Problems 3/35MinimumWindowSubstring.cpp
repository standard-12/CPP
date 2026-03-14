#include<bits/stdc++.h>
using namespace std;

// This was my solution but there was abetter way to check if the strign is valid rather than chechik using comp
// Which is illustrated in the next example
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> req(52,0);
        for(int i=0;i<t.size();i++){
            if(t[i]>='A' && t[i]<='Z') req[t[i]-'A'+26]++; 
            else req[t[i]-'a']++;
        }
        int reqlen=t.size();
        vector<int> curr(52,0);
        
        int n=s.size();
        int l=0,r=0;
        int start=-1,end=-1;

        while(r<n){
            if(s[r]>='A' && s[r]<='Z') curr[s[r]-'A'+26]++;
            else curr[s[r]-'a']++;
            

            while(comp(req,curr)){
                if(start==-1 || r-l+1<=end-start+1) {
                    start=l;
                    end=r;
                }
                if(s[l]>='A' && s[l]<='Z') curr[s[l]-'A'+26]--;
                else curr[s[l]-'a']--;
                l++;
            }

            r++;

        }
        if(start==-1 || end==-1) return "";
        return s.substr(start,end-start+1);
    }
            
        bool comp(vector<int>& req,vector<int>& curr){
            for(int i=0;i<52;i++){
                if(req[i]==0) continue;
                else if(req[i]>curr[i]) return false;
            }
            return true;
        }
};

// This was an intersting type of code writing 
// Same idea but uses counter variable
string minWindow(string s, string t) {
        vector<int> map(128,0);
        for(auto c: t) map[c]++;
        int counter=t.size(), begin=0, end=0, d=INT_MAX, head=0;
        while(end<s.size()){
            if(map[s[end++]]-->0) counter--; //in t
            while(counter==0){ //valid
                if(end-begin<d)  d=end-(head=begin);
                if(map[s[begin++]]++==0) counter++;  //make it invalid
            }  
        }
        return d==INT_MAX? "":s.substr(head, d);
    }

// The exact same solution but in readable but verbose way 
// Time Complexity O(2n + t.size()) Space Complexity O(52)
class Solution { 
public:
    string minWindow(string s, string t) {
        vector<int> hashTable(56,0);
        for(int i=0;i<t.size();i++){
            if(t[i]>='A' && t[i]<='Z') hashTable[t[i]-'A'+26]++;
            else hashTable[t[i]-'a']++;
        }
        int l=0;
        int r=0;
        int counter=t.size();
        int n=s.size();
        int start=-1,end=-1;
        while(r<n){
            if(s[r]>='A' && s[r]<='Z'){ 
                int ind=s[r]-'A'+26;
                if(hashTable[ind]>0) counter--;
                hashTable[ind]--;
            }
            else {
                int ind=s[r]-'a';
                if(hashTable[ind]>0) counter--;
                hashTable[ind]--;
            }
            
            while(counter==0){
                if(start==-1 || r-l+1<end-start+1) { 
                    start=l; 
                    end=r;
                }
                int ind=(s[l]>='A' && s[l]<='Z')? s[l]-'A'+26:s[l]-'a';
                hashTable[ind]++;
                if(hashTable[ind]==1) counter++;
                l++;
            }
            r++;

        }
        return start==-1? "":s.substr(start,end-start+1);
    }
};
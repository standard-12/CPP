#include<bits/stdc++.h>
using namespace std;

// In this problem i figured out if we use hashmap and sort it by value then it will be solved..so i was seeing how to sort unoredered_map using value
// it can be done using comparators(with vectors or sets) or using multimap

class Solution {
public:
    string frequencySort(string s) {
        int n=s.size();
        map<char,int> mp;
        for(char ch : s){
            mp[ch]++;
        }
        vector<pair<char,int>> v;
        for(auto& p:mp){
            v.push_back({p.first,p.second});
        }
        sort(v.begin(),v.end(),comp);
        string ans;
        for(int i=v.size()-1;i>=0;i--){
            for(int j=0;j<v[i].second;j++)
            ans.push_back(v[i].first);
        }
        return ans;
    }

    static bool comp(pair<char,int>& a,pair<char,int>& b){
        return a.second<b.second;
    }
};

// This is the optimal approach using bucket sorting 
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        for(char c : s) freq[c]++;
        
        vector<string> bucket(s.size() + 1);
        for(auto& f : freq) {
            char ch=f.first;
            int count=f.second;
            bucket[count].append(count, ch);
        }

        string ans;
        for(int i = s.size(); i >= 1; i--) {
            ans += bucket[i];
        }
        return ans;
    }
};

// Another solution uses priority_queue
class Solution {
public:
    string frequencySort(string s) {
        int n=s.size();
        unordered_map<char,int> freq;
        for(int i=0;i<n;i++) freq[s[i]]++;

        priority_queue<pair<int,char>> pq;
        for(auto& p : freq) {
            int count=p.first;
            char ch=p.second;
            pq.push({count,ch});
        }

        string ans;
        while(!pq.empty()){
            int f=pq.top().first;
            char ch=pq.top().second;
            pq.pop();
            ans.append(f,ch);
        }
        
        return ans;
    }
};
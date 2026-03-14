#include<bits/stdc++.h>
using namespace std;

// This is Contest no 480 3rd question
// LC 3776 

// I solved it on my own this is the O(n) and the optimal solution 
class Solution {
public:
    long long minMoves(vector<int>& balance) {
        int n=balance.size();
        long long moves=0;
        int neg=0;
        int negIndex=-1;
        long long sum=0;
        for(int i=0;i<n;i++){
            if(balance[i]<0){
                neg=balance[i];
                negIndex=i;
            }
            else 
                sum+=balance[i];
        }
        if(sum<abs(neg)) return -1;

        int i=negIndex-1;
        int j=negIndex+1;
        int steps=n/2;
        int dist=1;
        while(neg<0){
            if(i<0) i=i+n;
            if(j>=n) j=0;
            if(steps>0 && neg<0){
                moves+=1LL*min(balance[i],abs(neg))*dist;
                neg+=balance[i];
            }
            if(steps>0 && neg<0){
                moves+=1LL*min(balance[j],abs(neg))*dist;
                neg+=balance[j];
            }
            steps--;
            i--;
            j++;
            dist++;
        }
        return moves;
    }
};

// there is a priority_queue solution which is cleaner but has O(nlogn) time complexity
class Solution {
public:
    long long minMoves(vector<int>& balance) {
        struct comp{
            bool operator()(const pair<int,int>& a,const pair<int,int>& b){
                return a.first>b.first;
            }
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp> pq;
        int n=balance.size();
        int negVal=0;
        int negInd=-1;
        long long sum=0;
        for(int i=0;i<n;i++){
            if(balance[i]<0){
                negVal=balance[i];
                negInd=i;
            }
            else 
                sum+=balance[i];
        }
        if(sum<abs(negVal)) return -1;
        for(int i=0;i<n;i++){
            if(i!=negInd){
                int dist=min(abs(negInd-i),n-(abs(negInd-i)));
                int val=balance[i];
                pq.push({dist,val});
            }
        }
        long long move=0;
        while(negVal<0){
            auto p=pq.top();
            move+=1LL*min(p.second,abs(negVal))*p.first;
            negVal+=p.second;
            pq.pop();
        }
        return move;
    }
};
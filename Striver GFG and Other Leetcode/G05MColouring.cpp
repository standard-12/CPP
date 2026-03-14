#include<bits/stdc++.h>
using namespace std;

// I wrote this on my own this works but it check for all possibilities without any pruning and i am using adj matrix instead adj list.
// We can prune the solution considerably see below
class Solution {
  public:
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here
        vector<vector<int>> adjList(v,vector<int>(v,0));
        for(int i=0;i<edges.size();i++){
            adjList[edges[i][0]][edges[i][1]]=1;
            adjList[edges[i][1]][edges[i][0]]=1;
        }
        vector<int> colors;
        return recur(adjList,colors,m);
    }
    
    bool recur(vector<vector<int>>& adjList,vector<int>& colors,int m){
        if(colors.size()==adjList.size()){
            if(check(adjList,colors)){
                return true;
            }
            return false;
        }
        for(int i=0;i<m;i++){
            colors.push_back(i);
            if(recur(adjList,colors,m)) return true;
            colors.pop_back();
        }
        return false;
    }
    
    bool check(vector<vector<int>>& adjList,vector<int>& colors){
        int n=adjList.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(adjList[i][j]==0) continue;
                
                if( colors[i]==colors[j]) return false;
            }
        }
        return true;
    }
};

//  This is the optimal solution this check if it is possible to place before placing instead of
// my approach where i place and after everything is placed i check if its the right combination

class Solution {
  public:
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here
        vector<vector<int>> adjList(v);
        for(auto& e : edges){
            int a=e[0];
            int b=e[1];
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }
        vector<int> colors(v,-1);
        return recur(0,m,adjList,colors);
    }
    
    bool recur(int node,int m,vector<vector<int>>& adjList,vector<int>& colors){
        if(node==adjList.size()){
            return true;
        }
        for(int i=0;i<m;i++){
            if(isSafe(i,node,adjList,colors)){
                colors[node]=i;
                if(recur(node+1,m,adjList,colors)) return true;
                colors[node]=-1;
            }
        }
        return false;
    }
    
    bool isSafe(int color,int node,vector<vector<int>>& adjList,vector<int>& col){
        for(int v : adjList[node]){
            if(col[v]==color) return false;
        }
        return true;
    }
};
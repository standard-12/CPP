#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void dfs(int node,vector<bool>& visited,stack<int>& st,vector<vector<int>>& adj){
    visited[node]=true;

    for(int neighbour: adj[node]){
        if (visited[neighbour] != true)
        {
            dfs(neighbour,visited,st,adj);
        }
        st.push(node);
    }
}

vector<int> topologicalSort(int V,vector<vector<int>> adj){
    vector<bool> visited(V,false);
    stack<int> st;

    for(int i=0;i<V;i++){
        if(visited[i]!=true){
            dfs(i,visited,st,adj);
        }
    }

    vector<int> topo;
    while(!st.empty()){
        topo.push_back(st.top());
        st.pop();
    }
    return topo;

}
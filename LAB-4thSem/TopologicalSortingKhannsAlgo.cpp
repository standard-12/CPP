#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> KhansTopo(int V,vector<vector<int>> adj){
    vector<int> indegree(V,0);
    queue<int> qu;

    for(int u=0;u<V;u++){
        for(int v:adj[u]){
            indegree[v]++;
        }
    }

    for(int i=0;i<V;i++){
        if(indegree[i]==0) qu.push(i);
    }
    vector<int> topo;
    while (!qu.empty())
    {
        int current=qu.front();
        qu.pop();
        topo.push_back(current);

        for(int v: adj[current]){
            indegree[v]--;
            if(indegree[v]==0) qu.push(v);
        } 
    }

    return topo;
    
}
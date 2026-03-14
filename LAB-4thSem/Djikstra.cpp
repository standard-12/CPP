#include<queue>
#include<vector>
#include<utility>
#include<climits>
#include<iostream>

using namespace std;

vector<int> djikstra ( int v,vector<vector<pair<int,int>>>& adj,int S){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dist(v,INT_MAX);


    dist[S]=0;
    pq.push({0,S});

    while(!pq.empty()){
        int dis=pq.top().first;
        int node=pq.top().second;
        pq.pop();

        for(auto it: adj[node]){
            int adjnode=it.first;
            int edgeweight=it.second;
            if(dis+edgeweight<dist[adjnode]){
                dist[adjnode]=dis+edgeweight;
                pq.push({dist[adjnode],adjnode});
            }            
        }
    }
    return dist;
}

int main() {
    int n;
    cout<<"Enter no of vertices:";
    cin>>n;
    vector<vector<int>> adj(n,vector<int> (n,0));
    cout<<"Enter the adjoint matrix with weights";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>adj[i][j];
        }
    }

    vector<vector<pair<int, int>>> pairedadj(n); 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[i][j] != 0 && i != j) { 
                pairedadj[i].push_back({j, adj[i][j]});
            }
        }
    }
    vector<int> result;
    int source;
    cout<<"Enter source node :";
    cin>>source;
    result= djikstra(n,pairedadj,source);

    for(int i=0;i<result.size();i++){
        cout << "Distance from " << source << " to " << i << " is ";
        if (result[i] == INT_MAX)
            cout << "Unreachable" << endl;
        else
            cout << result[i] << endl;
    }
    return 0;
}

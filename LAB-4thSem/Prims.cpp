#include<queue>
#include<iostream>
#include<vector>

using namespace std;

vector<pair<int,int>> primMST ( int V,vector<vector<pair<int,int>>>& adj, int start){
    vector<int> visited(V,0);
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> pq;
    vector<pair<int,int>> mstedges;

    pq.push({0,{start,-1}});

    while(!pq.empty()){
        pair<int,pair<int,int>> temp=pq.top();
        pq.pop();
        int weight=temp.first;
        int toNode=temp.second.first;
        int fromNode=temp.second.second;

        if(visited[toNode]) continue;

        visited[toNode]=1;

        if(fromNode!=-1){
            mstedges.push_back({fromNode,toNode});
        }

        for(auto it : adj[toNode]){
            int adjNode=it.first;
            int adjWeight=it.second;
            if(!visited[adjNode])
            pq.push({adjWeight,{adjNode,toNode}});
        }
    }
    return mstedges;
}

int main() {
    int n;
    cout<<"Enter no of vertices : ";
    cin>>n;

    vector<vector<int>> adj(n,vector<int> (n));
    cout<<"Enter the adjacency matrix : "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>adj[i][j];
        }
    }

    int start;
    cout<<"Enter Start Vertex : ";
    cin>>start;

    vector<vector<pair<int,int>>> finaladj(n);

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(adj[i][j]!=0 && i!=j)
                  finaladj[i].push_back({j,adj[i][j]});
    
    vector<pair<int,int>> result=primMST(n,finaladj,start);

    int totalcost=0;
    cout<<"Edges in MST : \n";
    for(auto it : result){
        int from=it.first;
        int to=it.second;
        int cost=adj[from][to];
        totalcost += cost;
        cout<<from<<" - "<<to<<" cost : "<<cost<<endl;
    }
    cout<<"Total Cost of MST: "<<totalcost<<endl;

    return 0;
}
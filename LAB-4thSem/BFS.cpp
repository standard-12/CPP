#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> BFS(vector<vector<int>> adj, int start,vector<int>& spanningtree){
    int size=adj.size();
    vector<bool> visited(size,false);
    queue<int> qu;
    vector<int> finaltraversal;
    qu.push(start);
    visited[start]=true;

    while(!qu.empty()){
        int current = qu.front();
        qu.pop();
        finaltraversal.push_back(current);

        for(int i=0;i<size;i++){
            if(adj[current][i]==1 && visited[i]==false){
                visited[i]=true;
                spanningtree[i]=current;
                qu.push(i);
            }
        }
    }
    return finaltraversal;
}

int main(){
    vector<vector<int>> adj;
    vector<int> result;
    int n;
    cout<<"Enter the no of nodes :"<<endl;
    cin>>n;
    cout<<"Enter adj matrix: ";
    adj.resize(n, vector<int>(n, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>adj[i][j];
        }
    }
    vector<int> spantree(n,-1);
    result=BFS(adj,1,spantree);
    cout<<"BFS traversal is = "<<endl;
    for(auto it : result){
        cout<<it<<" ";
    }
    cout<<"Spaning tree is Parent-> Child :";
    for(int i=0;i<n;i++){
        if(spantree[i]!=-1){
            cout<<spantree[i]<<"-->"<<i<<endl;
        }
    }
    return 0; 
}
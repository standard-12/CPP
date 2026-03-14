#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> DFS(vector<vector<int>> adj , int start){
    int size=adj.size();
    vector<bool> visited(size,false);
    stack<int> st;
    vector<int> finaltraversal;
    st.push(start);
    visited[start]=true;

    while(!st.empty()){
        int current = st.top();
        st.pop();
        finaltraversal.push_back(current);

        for(int i=size-1;i>=0;i++){
            if(adj[current][i]==1 && visited[i]==false){
                visited[i]=true;
                st.push(i);
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
    result=DFS(adj,0);
    cout<<"DFS traversal is = "<<endl;
    for(auto it : result){
        cout<<it;
    }

    

}
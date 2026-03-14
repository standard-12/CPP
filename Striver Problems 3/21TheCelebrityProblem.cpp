#include<bits/stdc++.h>
using namespace std;

// This que is in gfg 
// And this was my solution and it worked 

class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int rows=mat.size();
        int cols=mat[0].size();
        for(int i=0;i<cols;i++){
            bool b=true;
            for(int j=0;j<rows;j++){
                if(mat[j][i]==0) {
                    b=false;
                    break;
                }
            }
            if(b){
                bool b=true;
                for(int k=0;k<cols;k++){
                    if(i!=k && mat[i][k]==1) b=false;
                }
                if(b) return i;
            }
        }
        return -1;
    }
};

//this doesnt use stack or queue
class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        vector<int> iknow(n,0);
        vector<int> knowme(n,0);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    iknow[i]++;
                    knowme[j]++;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(iknow[i]==1 && knowme[i]==n) return i;
        }
        return -1;
    }
};

// There is a more optimal solution using stack
// Time Complexity O(n)
class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        stack<int> st;
        int row=mat.size();
        for(int i=0;i<row;i++){
            st.push(i);
        }
        
        while(st.size()>1){
            int a=st.top();st.pop();
            int b=st.top();st.pop();
            
            if(mat[a][b]==1){
                st.push(b);
            }
            else {
                st.push(a);
            }
        }
        
        int cand=st.top();
        for(int i=0;i<row;i++){
            if(i!=cand && (mat[cand][i]==1 || mat[i][cand]==0)){
                return -1;
            }
        }
        return cand;
    }
};

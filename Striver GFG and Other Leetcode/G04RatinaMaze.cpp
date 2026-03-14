#include<bits/stdc++.h>
using namespace std;

// This if passing string  by pass by reference
class Solution {
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        vector<string> ans;
        string s;
        recur(0,0,maze,ans,s);
        return ans;
    }
    void recur(int row,int col,vector<vector<int>>& maze,vector<string>& ans,string& s){
        int n=maze.size();
        if(row==n-1 && col==n-1){
            ans.push_back(s);
            return;
        }
        if(row>=n || row<0 || col>=n || col<0) return;
        if(maze[row][col]==0) return;
        maze[row][col]=0;
        s.push_back('D');
        recur(row+1,col,maze,ans,s);
        s.pop_back();
        
        s.push_back('L');
        recur(row,col-1,maze,ans,s);
        s.pop_back();

        s.push_back('R');
        recur(row,col+1,maze,ans,s);
        s.pop_back();
        
        s.push_back('U');
        recur(row-1,col,maze,ans,s);
        s.pop_back();
        
        maze[row][col]=1;
    }
};

// This code if your passing string by value

class Solution {
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        vector<string> ans;
        // string s;
        recur(0,0,maze,ans,"");
        return ans;
    }
    void recur(int row,int col,vector<vector<int>>& maze,vector<string>& ans,string/*&*/ s){
        int n=maze.size();
        if(row==n-1 && col==n-1){
            ans.push_back(s);
            return;
        }
        if(row>=n || row<0 || col>=n || col<0) return;
        if(maze[row][col]==0) return;
        maze[row][col]=0;
        // s.push_back('D');
        recur(row+1,col,maze,ans,s+"D");
        // s.pop_back();
        
        // s.push_back('L');
        recur(row,col-1,maze,ans,s+"L");
        // s.pop_back();

        // s.push_back('R');
        recur(row,col+1,maze,ans,s+"R");
        // s.pop_back();
        
        // s.push_back('U');
        recur(row-1,col,maze,ans,s+"U");
        // s.pop_back();
        
        maze[row][col]=1;
    }
};
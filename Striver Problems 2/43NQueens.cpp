#include<bits/stdc++.h>
using namespace std;

// Yeee i solved this on my own hurray it was related to chess so it has an emotional element to it also

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        vector<vector<int>> vis(n,vector<int>(n,0));
        recur(0,0,n,board,ans,vis);
        return ans;
    }

    void recur(int rowno,int queensplaced,int n,vector<string>& board,vector<vector<string>>& ans,vector<vector<int>>& vis){
        if(queensplaced==n){
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;i++){
            if(vis[rowno][i]==0){
                board[rowno][i]='Q';
                placequeen(rowno,i,vis);
                recur(rowno+1,queensplaced+1,n,board,ans,vis);
                board[rowno][i]='.';
                removequeen(rowno,i,vis);
            }
        }
    }

    void placequeen(int row,int col,vector<vector<int>>& vis){
        int n=vis.size();
        for(int i=row+1;i<n;i++){ // Going Vertically down and adding 1 to all squares in board
            vis[i][col]++;
        }
        int r=row+1;
        int c=col+1;
        while(c<n && r<n){  // Adding diagnolly to right of where the queen is 
            vis[r][c]++;
            r++;
            c++;
        }
         r=row+1;
         c=col-1;
        while(r<n && c>=0){ //Adding one to right diagonal
            vis[r][c]++;
            r++;
            c--;
        }
    }

    void removequeen(int row,int col,vector<vector<int>>& vis){
        int n=vis.size();
        for(int i=row+1;i<n;i++){ // Going Vertically down and subtracting 1 to all squares in board
            vis[i][col]--;
        }
        int r=row+1;
        int c=col+1;
        while(c<n && r<n){  // Subtracting 1 diagnolly to right of where the queen is 
            vis[r][c]--;
            r++;
            c++;
        }
         r=row+1;
         c=col-1;
        while(r<n && c>=0){ //Subtracting 1 to right diagonal
            vis[r][c]--;
            r++;
            c--;
        }

    }
};


// Optimized code which uses less space complexity 
// makes use of addition of rows and columns (see striver solution sheet for chess board)

#include <bits/stdc++.h>

using namespace std;
class Solution {
  public:
    void solve(int col, vector < string > & board, vector < vector < string >> & ans, vector < int > & leftrow, vector < int > & upperDiagonal, vector < int > & lowerDiagonal, int n) {
      if (col == n) {
        ans.push_back(board);
        return;
      }
      for (int row = 0; row < n; row++) {
        if (leftrow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) {
          board[row][col] = 'Q';
          leftrow[row] = 1;
          lowerDiagonal[row + col] = 1;
          upperDiagonal[n - 1 + col - row] = 1;
          solve(col + 1, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
          board[row][col] = '.';
          leftrow[row] = 0;
          lowerDiagonal[row + col] = 0;
          upperDiagonal[n - 1 + col - row] = 0;
        }
      }
    }

  public:
    vector < vector < string >> solveNQueens(int n) {
      vector < vector < string >> ans;
      vector < string > board(n);
      string s(n, '.');
      for (int i = 0; i < n; i++) {
        board[i] = s;
      }
      vector < int > leftrow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
      solve(0, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
      return ans;
    }
};
int main() {
  int n = 4; // we are taking 4*4 grid and 4 queens
  Solution obj;
  vector < vector < string >> ans = obj.solveNQueens(n);
  for (int i = 0; i < ans.size(); i++) {
    cout << "Arrangement " << i + 1 << "\n";
    for (int j = 0; j < ans[0].size(); j++) {
      cout << ans[i][j];
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}
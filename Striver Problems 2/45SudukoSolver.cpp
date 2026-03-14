#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        bool b=recur(board);
    }

    // bool recur(int row,int col,vector<vector<int>>& rowHash,vector<vector<int>>& colHash,vector<vector<int>>& boxHash){
        bool recur(vector<vector<char>>& board){

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char k='1';k<='9';k++){                      
                        if(solve(board,i,j,k)) {
                            board[i][j]=k;
                            if(recur(board)) return true;
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board,int row,int col,char k){
        char ch=k;
        for(int i=0;i<9;i++){
            if(board[row][i]==ch) return false;
            if(board[i][col]==ch) return false;
        }
        int srow= row/3 * 3;
        int scol= col/3 * 3;
        for(int i=srow;i<srow+3;i++){
            for(int j=scol;j<scol+3;j++){
                if(board[i][j]==ch) return false;
            }
        }
        return true;
    }
};

// This uses more space but does it in a better way and uses less time more efficient
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        int n=board.size();
        vector<vector<int>> rowHash(n,vector<int>(n,0));
        vector<vector<int>> colHash(n,vector<int>(n,0));
        vector<vector<int>> boxHash(n,vector<int>(n,0));
        ilize(board,rowHash,colHash,boxHash);
        bool b=recur2(board,0,0,rowHash,colHash,boxHash);
    }
 
 bool recur2(vector<vector<char>>& board,int row,int col,vector<vector<int>>& rowHash,vector<vector<int>>& colHash,vector<vector<int>>& boxHash){
        if(row==board.size()){
            return true;
        }
        if(col==board.size()){
            col=0;
            row++;
            if(row==board.size()) return true; 
        }
        if(board[row][col]!='.'){
            return recur2(board,row,col+1,rowHash,colHash,boxHash);
        }
        for(char k='1';k<='9';k++){
            int num=k-'1';
            int box=row/3 * 3 + col/3;

            if(rowHash[row][num] || colHash[col][num] || boxHash[box][num]) continue;
            
                board[row][col]=k;
                rowHash[row][num]=1;
                colHash[col][num]=1;
                boxHash[box][num]=1;
            
            if(recur2(board,row,col+1,rowHash,colHash,boxHash)) return true;
            
                board[row][col]='.';
                rowHash[row][num]=0;
                colHash[col][num]=0;
                boxHash[box][num]=0;
            
        }
        return false;
 }
    
    void ilize(vector<vector<char>>& board,vector<vector<int>>& rowHash,vector<vector<int>>& colHash,vector<vector<int>>& boxHash){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                int box=i/3 * 3 + j/3;
                int num=board[i][j]-'1';
                rowHash[i][num]=1;
                colHash[j][num]=1;
                boxHash[box][num]=1;
            }
        }
    }
};
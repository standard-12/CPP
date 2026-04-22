#include<bits/stdc++.h>
using namespace std;


// This is a multi source BFS problem ( Graph - I had not done graph at this time so i coulnd't solve )
// Below is the solution

// Time Complexity O(nlogn) if we use hashmap then O(n)
class tri{
    public:
        int row,col,color;

        tri(int row,int col,int color){
            this->row=row;
            this->col=col;
            this->color=color;
        }
};

class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> ans(n,vector<int>(m,0));
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        queue<tri> qu;
        for(auto& vec:sources){
            ans[vec[0]][vec[1]]=vec[2];
            vis[vec[0]][vec[1]]=true;
            qu.push(tri(vec[0],vec[1],vec[2]));
        }

        vector<int> dr={-1,1,0,0};  
        vector<int> dc={0,0,-1,1};

        while(!qu.empty()){
            int size=qu.size();
            map<pair<int,int>,int> mp;

            for(int i=0;i<size;i++){
                tri temp=qu.front();
                qu.pop();
                int r=temp.row;
                int c=temp.col;
                int color=temp.color;

                for(int i=0;i<4;i++){
                    int newr=r+dr[i];
                    int newc=c+dc[i];
                    
                    if(newr < 0 || newr >= n || newc < 0 || newc >= m) continue;

                    if(vis[newr][newc]) continue;
                    
                    if(mp.find({newr,newc})!=mp.end()){
                            mp[{newr,newc}]=max(mp[{newr,newc}],color);
                        }
                    else {
                            mp[{newr,newc}]=color;
                        }
                    
                }
            }

            for (auto &it : mp) {
                int row = it.first.first;
                int col = it.first.second;
                int color = it.second;

                ans[row][col] = color;
                vis[row][col] = true;
                qu.push({row, col, color});
            }
        }
        return ans;
    }
};

// The optimal method O(n) Average (but same indicies nodes will be pushed multiple times to the queue)

class Solution {
public:
    class Triplet {
    public:
        int row, col, color;

        Triplet(int row, int col, int color) {
            this->row = row;
            this->col = col;
            this->color = color;
        }
    };

    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        queue<Triplet> queue;

        vector<vector<int>> grid(n, vector<int>(m, 0));
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        for (auto &arr : sources) {
            int row = arr[0];
            int col = arr[1];
            int color = arr[2];

            grid[row][col] = color;
            dist[row][col] = 0;

            queue.push(Triplet(row, col, color));
        }

        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};

        while (!queue.empty()) {
            Triplet temp = queue.front();
            queue.pop();

            int row = temp.row;
            int col = temp.col;
            int color = temp.color;

            for (int i = 0; i < 4; i++) {
                int newRow = row + dr[i];
                int newCol = col + dc[i];

                if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= m)
                    continue;

                if (dist[newRow][newCol] == INT_MAX) {
                    dist[newRow][newCol] = dist[row][col] + 1;
                    grid[newRow][newCol] = color;
                    queue.push(Triplet(newRow, newCol, color));
                }
                else if (dist[newRow][newCol] == dist[row][col] + 1) {
                    if (color > grid[newRow][newCol]) {
                        grid[newRow][newCol] = color;
                        queue.push(Triplet(newRow, newCol, color)); // kept as-is
                    }
                }
            }
        }

        return grid;
    }
};
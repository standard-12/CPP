#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

// I couldn't solve this on my own and the below code is also using a extra for loop 
// Extra for loop is not necessary because always the first node will be the minimum 
// I was using extra for loop for calucalting minimum
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>> qu;
        if(!root) return 0;
        qu.push({root,0});
        int ans=INT_MIN;
        while(!qu.empty()){
            int size=qu.size();
            vector<pair<TreeNode*,long long>> vec;
            long long  levelMini=INT_MAX;
            for(int i=0;i<size;i++){
                pair<TreeNode*,long long> p=qu.front();qu.pop();
                vec.push_back({p.first,p.second});
                levelMini=min(levelMini,p.second);
            }
            for(int i=0;i<size;i++){
                ans=max((long long)ans,vec[i].second-levelMini+1);
                if(vec[i].first->left){
                    long long  newVal=(long long)(vec[i].second-levelMini)*2+1;
                    qu.push({vec[i].first->left,newVal});
                }
                if(vec[i].first->right){
                    long long  newVal=(long long)(vec[i].second-levelMini)*2+2;
                    qu.push({vec[i].first->right,newVal});
                }
            }
        }
        return ans;
    }

};
// The Optimal Solution is 
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>> qu;
        if(!root) return 0;
        qu.push({root,0});
        int ans=INT_MIN;
        while(!qu.empty()){
            int size=qu.size();
            long long  levelMini=INT_MAX;
            for(int i=0;i<size;i++){
                pair<TreeNode*,long long> p=qu.front();qu.pop();
                if(i==0){
                    levelMini=p.second;
                }
                ans=max((long long)ans,p.second-levelMini+1);
                if(p.first->left){
                    long long  newVal=(long long)(p.second-levelMini)*2+1;
                    qu.push({p.first->left,newVal});
                }
                if(p.first->right){
                    long long  newVal=(long long)(p.second-levelMini)*2+2;
                    qu.push({p.first->right,newVal});
                }
            }
        }
        return ans;
    }

};
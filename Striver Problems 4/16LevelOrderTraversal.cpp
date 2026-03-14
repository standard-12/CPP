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

// This was my solution i used another variable with TreeNode* to get the level  
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return {};
        queue<pair<TreeNode*,int>> q;
        int max=height(root);
        vector<vector<int>> ans(max);
        q.push({root,0});
        while(!q.empty()){
            pair<TreeNode*,int> p=q.front();
            q.pop();
            ans[p.second].push_back(p.first->val);
            if(p.first->left) q.push({p.first->left,p.second+1});
            if(p.first->right) q.push({p.first->right,p.second+1});

        }
        return ans;
    }

    int height(TreeNode* root){
        if(root==NULL) return 0;
        int leftHeight=height(root->left);
        int rightHeight=height(root->right);
        return max(leftHeight,rightHeight)+1;
    }
};

// We can do it without that ( This is the optimal solution )

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> qu;
        vector<vector<int>> ans;
        if(!root) return ans;
        qu.push(root);
        while(!qu.empty()){
            int size=qu.size();
            vector<int> level;

            for(int i=0;i<size;i++){
                TreeNode* temp=qu.front();
                qu.pop();
                level.push_back(temp->val);

                if(temp->left) qu.push(temp->left);
                if(temp->right) qu.push(temp->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};
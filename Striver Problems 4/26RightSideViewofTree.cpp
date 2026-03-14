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

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<pair<TreeNode*,int>> qu;
        map<int,int> mp;
        if(root)qu.push({root,0});
        while(!qu.empty()){
            pair<TreeNode*,int> p=qu.front();qu.pop();
            TreeNode* temp=p.first;
            int row=p.second;
            if(temp->left) qu.push({temp->left,row+1});
            if(temp->right) qu.push({temp->right,row+1});
            mp[row]=temp->val;
        }
        vector<int> ans;
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
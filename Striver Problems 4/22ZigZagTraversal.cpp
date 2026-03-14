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

// I solved this on my own and a minor optimization is possible which is shown below

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> qu;
        vector<vector<int>> ans;
        if(!root) return ans;
        qu.push(root);
        bool flag=true;
        while(!qu.empty()){
            int size=qu.size();
            vector<int> temp;

            for(int i=0;i<size;i++){
                TreeNode* t = qu.front();
                qu.pop();
                int val=t->val;
                if(t->left) qu.push(t->left);
                if(t->right) qu.push(t->right);
                temp.push_back(val);
            }
            flag=!flag;
            if(flag) reverse(temp.begin(),temp.end());
            ans.push_back(temp);
        }       
        return ans;
    }
};

// The minor optimization that could be done is : To remove the reverse function

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> qu;
        vector<vector<int>> ans;
        if(!root) return ans;
        qu.push(root);
        bool flag=true;
        while(!qu.empty()){
            int size=qu.size();
            vector<int> temp(size);

            for(int i=0;i<size;i++){
                TreeNode* t = qu.front();
                qu.pop();
                int val=t->val;
                if(t->left) qu.push(t->left);
                if(t->right) qu.push(t->right);

                int index=flag? i:(size-1-i);
                temp[index]=val;

            }
            flag=!flag;
            // if(flag) reverse(temp.begin(),temp.end());
            ans.push_back(temp);
        }       
        return ans;
    }
};
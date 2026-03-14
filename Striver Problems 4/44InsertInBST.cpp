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
// This was my solution and it is the optimal one 
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        TreeNode* curr=root;
        TreeNode* prev=NULL;
        while(curr){
            prev=curr;
            if(curr->val>val){
                curr=curr->left;
            }
            else {
                curr=curr->right;
            }
        }
        if(prev->val<val) prev->right=new TreeNode(val);
        else prev->left=new TreeNode(val);
        return root;
    }
};
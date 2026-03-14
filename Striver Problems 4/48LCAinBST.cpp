#include<bits/stdc++.h>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
// This was my solution but it was exact copy of normal tree solution and i wasn't using the FACT THAT THIS IS A BST

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root==p) return p;
        if(root==q) return q;

        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        if(left && right) return root;
        if(left==NULL) return right;
        else return left;
    }
};

// This is the optimal solution this goes to left only if it's value is less
// MAIN IDEA : We have access to values through p->val and q->val ( in binary tree it can be in either side but in BST 
// we can figure out which side it will be )
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root->val>p->val && root->val>q->val) return lowestCommonAncestor(root->left,p,q);
        if(root->val<p->val && root->val<q->val) return lowestCommonAncestor(root->right,p,q);
        return root;
    }
};
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
 // I just used the code for same tree and just changed left with right and right with left to one of the trees
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
         if(root && root->left && root->right) return traverseTwo(root->left,root->right);  
         if(!root || (!root->left && !root->right)) return true;
         return false;
    }
     bool traverseTwo(TreeNode* p,TreeNode* q){
        if(!p && !q) return true;
        if(!p || !q) return false;
        if(p->val != q->val) return false;
        if(!traverseTwo(p->left,q->right)) return false; // See the change here
        if(!traverseTwo(p->right,q->left)) return false; // And here
        return true;
    } 
};
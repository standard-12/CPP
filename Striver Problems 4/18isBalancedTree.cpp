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

// This was my solution and this the brute force solution
// Time Complexity O(n^2) Space Complexity O(h)

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int left=height(root->left);
        int right=height(root->right);
        if(abs(right-left)>1) return false;
        if(!isBalanced(root->left))  return false;
        if(!isBalanced(root->right)) return false;
        return true;
    }
    int height(TreeNode* root){
        if(!root) return 0;
        int leftHeight=height(root->left);
        int rightHeight=height(root->right);
        return max(leftHeight,rightHeight)+1;
    }
};

// The optimal O(n) solution

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return height(root)!=-1;
    }
    
    int height(TreeNode* root){
        if(root==NULL) return 0;
        
        int left=height(root->left);
        int right=height(root->right);
        
        //Add these 2 lines for the same height function
        if(left==-1 || right==-1) return -1;
        if(abs(left-right)>1) return -1;

        return max(left,right)+1;
    }
};
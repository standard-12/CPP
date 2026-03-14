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

// This was my solution but it uses a space complexity of O(n)
// Time Complexity O(2n) 
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        vector<int> inorder;
        bool b=traverse(root,inorder);
        if(!b) return false;
        else {
            int n=inorder.size();
            for(int i=1;i<n;i++){
                if(inorder[i]<=inorder[i-1]) return false;
            }
        }
        return true;
    }

    bool traverse(TreeNode* root,vector<int>& inorder){
        if(!root) return true;

        if(root->left ){ // These conditions are only to optimize the solution like if we found a direct violation of BST we immediately return
            if(root->left->val<root->val){ 
                if(!traverse(root->left,inorder)) return false;
            }
            else return false;
        }
        inorder.push_back(root->val);
        if(root->right){
            if(root->right->val>root->val){
                if(!traverse(root->right,inorder)) return false;
            }
            else return false;
        }
        return true;
    }
};

// This is the optimal solution 
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return recur(root,LLONG_MIN,LLONG_MAX);
    }

    bool recur(TreeNode* root,long long  minVal,long long  maxVal){
        if(!root) return true;
        if(root->val>=maxVal || root->val<=minVal) return false;
        return recur(root->left,minVal,root->val) && recur(root->right,root->val,maxVal); 
    }
};
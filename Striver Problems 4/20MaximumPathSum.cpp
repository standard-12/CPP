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
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        int num=recur(root,maxi);
        return maxi;
    }

    int recur(TreeNode* root,int& maxi){
        if(!root) return 0;
        int leftSum=recur(root->left,maxi);
        int rightSum=recur(root->right,maxi);
        maxi=max(maxi,leftSum+rightSum+root->val);
        return max(0,root->val+max(leftSum,rightSum));
    }
};
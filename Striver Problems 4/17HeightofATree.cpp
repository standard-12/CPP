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

// There are 2 methods for finding the height of a tree one is Level Order Traversal and the other one is the Recursive method
// Time Complexity (for level ordee) O(n) Space Complexity O(n) (worst case) (bad for sparsed trees good for skewed trees)

// Time Complexity (for Recursive) O(n) Space Complexity O(h) where h is the height of the tree (bad for skewed trees good for sparse trees)

class Solution {
public:
    int maxDepth(TreeNode* root) {
        return height(root);
    }

    int height(TreeNode* root){
        if(!root) return 0;
        int leftHeight=height(root->left);
        int rightHeight=height(root->right);
        return max(leftHeight,rightHeight)+1;
    }
};
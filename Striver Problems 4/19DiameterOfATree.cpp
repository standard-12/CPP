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

// I solved it on my own and this is optimal Time Complexity O(n) Space Complexity O(h)
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int,int> p=getValues(root);
        return p.first;
    }

    pair<int,int> getValues(TreeNode* root){
        if(!root) return {0,0};

        pair<int,int> left=getValues(root->left);
        pair<int,int> right=getValues(root->right);

       int diameter=max(left.first,max(right.first,left.second+right.second)); 
       int height=max(left.second,right.second)+1;
       return {diameter,height};
    }
};

// This is another solution ( a bit more nice but same complexity)
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int d=0;
        height(root,d);
        return d;
    }

    int height(TreeNode* root,int& d){
        if(root==NULL) return 0;
        
        int left=height(root->left,d);
        int right=height(root->right,d);
        d=max(d,left+right);
        return max(left,right)+1;
    }
};
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
    unordered_map<int,int> inorderIndex;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++){
            inorderIndex[inorder[i]]=i;
        }

        return build(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    }

    TreeNode* build(vector<int>& inorder,int inStart,int inEnd,vector<int>& postorder,int postStart,int postEnd){
        if(inStart>inEnd || postStart>postEnd) return nullptr;

        int rootVal=postorder[postEnd];
        int rootIndex=inorderIndex[rootVal];

        TreeNode* root=new TreeNode(rootVal);
        int leftSize=rootIndex-inStart;
        root->left=build(inorder,inStart,rootIndex-1,postorder,postStart,postStart+leftSize-1);
        root->right=build(inorder,rootIndex+1,inEnd,postorder,postStart+leftSize,postEnd-1);

        return root;
    }
};
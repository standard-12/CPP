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
// This was my solution which didn't work but the idea was right only implementation i couldn't figure out
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root=new TreeNode(preorder[0]);
        splitter(preorder,inorder,root);
        return root;
    }

    void splitter(vector<int> preorder,vector<int> inorder,TreeNode* root){
        if(preorder.size()<=1) return;
        int rootVal=preorder[0];
        int rootIndex=-1;
        int n=inorder.size();
        for(int i=0;i<n;i++){
            if(rootVal==inorder[i]){
                rootIndex=i;
                break;
            }
        }
        int leftIndex=1; // This is the index of leftChild in preOrder
        int rightIndex=1+rootIndex; // This is the index of rightChild in preOrder
        TreeNode* left=NULL;
        TreeNode* right=NULL;
        if(leftIndex<preorder.size()) {
            left=buildLeft(root,preorder[leftIndex]);
            vector<int> newPreOrder;
            vector<int> newInOrder;

            newPreOrder.assign(preorder.begin()+1,preorder.begin()+1+rootIndex);
            newInOrder.assign(inorder.begin(),inorder.begin()+rootIndex);
            splitter(newPreOrder,newInOrder,left);        
        }
        if(rightIndex<preorder.size()){
            right=buildRight(root,preorder[rightIndex]);
            vector<int> newPreOrder;
            vector<int> newInOrder;

            newPreOrder.assign(preorder.begin()+1+rootIndex,preorder.end());
            newInOrder.assign(inorder.begin()+1+rootIndex,inorder.end());
            splitter(newPreOrder,newInOrder,right);
        }
    }

    TreeNode* buildLeft(TreeNode* parent,int value){
        TreeNode* newNode=new TreeNode(value);
        parent->left=newNode;
        return newNode;
    }
    TreeNode* buildRight(TreeNode* parent,int value){
        TreeNode* newNode=new TreeNode(value);
        parent->right=newNode;
        return newNode;
    }
};

// These were the changes needed to make my code work 
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        // 🔴 ADDED: handle empty input
        if(preorder.empty()) return nullptr;

        TreeNode* root = new TreeNode(preorder[0]);

        // 🔴 CHANGED: pass vectors by reference (no copying at function call)
        splitter(preorder, inorder, root);

        return root;
    }

    // 🔴 CHANGED: vectors are now passed by reference (&)
    void splitter(vector<int>& preorder,
                  vector<int>& inorder,
                  TreeNode* root) {

        // 🔴 CHANGED: base case must handle size <= 1
        if(preorder.size() <= 1) return;

        int rootVal = preorder[0];

        // 🔴 same logic but cleaner
        int rootIndex = 0;
        while(inorder[rootIndex] != rootVal) rootIndex++;

        // ================= LEFT SUBTREE =================

        // 🔴 CHANGED:
        // Instead of checking leftIndex < preorder.size(),
        // we check if left subtree actually exists.
        // Left subtree exists only if rootIndex > 0
        if(rootIndex > 0) {

            // 🔴 CHANGED:
            // Use direct constructor instead of assign()
            vector<int> leftPre(preorder.begin() + 1,
                                preorder.begin() + 1 + rootIndex);

            vector<int> leftIn(inorder.begin(),
                               inorder.begin() + rootIndex);

            // 🔴 CHANGED:
            // Create left node ONLY if subtree exists
            TreeNode* leftNode = new TreeNode(leftPre[0]);
            root->left = leftNode;

            splitter(leftPre, leftIn, leftNode);
        }

        // ================= RIGHT SUBTREE =================

        // 🔴 CHANGED:
        // Right subtree exists only if rootIndex < inorder.size()-1
        if(rootIndex < inorder.size() - 1) {

            vector<int> rightPre(preorder.begin() + 1 + rootIndex,
                                 preorder.end());

            vector<int> rightIn(inorder.begin() + rootIndex + 1,
                                inorder.end());

            TreeNode* rightNode = new TreeNode(rightPre[0]);
            root->right = rightNode;

            splitter(rightPre, rightIn, rightNode);
        }
    }
};

// This was the chatgpt solution but still with space but with return type TreeNode*
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return splitter(preorder, inorder);
    }

    TreeNode* splitter(vector<int>& preorder, vector<int>& inorder) {

        if(preorder.empty()) return nullptr;

        int rootVal = preorder[0];
        TreeNode* root = new TreeNode(rootVal);

        // find root index in inorder
        int rootIndex = 0;
        while(inorder[rootIndex] != rootVal) rootIndex++;

        // build left subtree vectors
        vector<int> leftPre(preorder.begin() + 1,
                            preorder.begin() + 1 + rootIndex);
        vector<int> leftIn(inorder.begin(),
                           inorder.begin() + rootIndex);

        // build right subtree vectors
        vector<int> rightPre(preorder.begin() + 1 + rootIndex,
                             preorder.end());
        vector<int> rightIn(inorder.begin() + rootIndex + 1,
                            inorder.end());

        root->left = splitter(leftPre, leftIn);
        root->right = splitter(rightPre, rightIn);

        return root;
    }
};

//This is the optimal solution with return type TreeNode without copying of vectors 
class Solution {
public:
    unordered_map<int,int> inorderIndex;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            inorderIndex[inorder[i]]=i;
        }
        return build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
    TreeNode* build(vector<int>& preorder,int preStart,int preEnd,vector<int>& inorder,int inStart,int inEnd){
        if(preStart>preEnd || inStart>inEnd) return NULL;
        int rootVal=preorder[preStart];
        TreeNode* root=new TreeNode(rootVal);

        int inrootIndex=inorderIndex[rootVal];
        int leftSize=inrootIndex-inStart;

        root->left = build(preorder,preStart+1,preStart+1+leftSize,inorder,inStart,inrootIndex-1);
        root->right = build(preorder,preStart+1+leftSize,preEnd,inorder,inrootIndex+1,inEnd);
        return root;
    }
};
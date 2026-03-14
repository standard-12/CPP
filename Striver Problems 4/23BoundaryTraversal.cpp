#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
// GFG
// This was my solution  and it is the optimal solution

class Solution {
  public:
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;
        if(!root) return ans;
        ans.push_back(root->data);
        if(root->left) getLeft(root->left,ans);
        getLeafs(root->left,ans);
        getLeafs(root->right,ans);
        if(root->right) getRight(root->right,ans);
        return ans;
    }
    
    void getLeft(Node* node,vector<int>& ans){
        if(!node->left && !node->right) return;
        ans.push_back(node->data);
        if(node->left) getLeft(node->left,ans);
        else if(node->right)  getLeft(node->right,ans);
    }
    
    void getLeafs(Node* node,vector<int>& ans){
        if(!node) return;
        if(!node->left && !node->right){
            ans.push_back(node->data);
            return;
        }
        getLeafs(node->left,ans);
        getLeafs(node->right,ans);
    }
    
    void getRight(Node* node,vector<int>& ans){
        if(!node->left && !node->right) return;
        if(node->right) getRight(node->right,ans);
        else if(node->left) getRight(node->left,ans);
        ans.push_back(node->data);
    }   
};


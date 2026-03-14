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

// Recursive Solution I could come up with this
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inOrder(root,ans);
        return ans;
    }

    void inOrder(TreeNode* root,vector<int>& ans){
        if(root==NULL) return;
        inOrder(root->left,ans);
        ans.push_back(root->val);
        inOrder(root->right,ans);
    }
};

// I couldn't come up with this solution 
// Here we change the pointer to right at the leaf of left subtree

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* curr=root;

        while(curr!=NULL || !st.empty()){
            while(curr!=NULL){
                st.push(curr);
                curr=curr->left;
            }
            curr=st.top();
            st.pop();
            ans.push_back(curr->val);
            curr=curr->right;
        }
        return ans;
    }
};

//Striver one same solution but more understandable with if else

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* node=root;
        while(true){
            if(node!=NULL){
                st.push(node);
                node=node->left;
            }
            else{
                if(st.empty()==true) break;
                node=st.top();
                st.pop();
                ans.push_back(node->val);
                node=node->right;
            }
        }
        return ans;
    }
};
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

// This was my solution it got accepted and also beated 100& BUT the worst case is O(n^2) and the solution is not efficient
// The idea was close but i used recursion in too many places just to flatten it should have done without recursion
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        TreeNode* curr=root;
        if(root->left){
            TreeNode* temp=curr->right;
            curr->right=curr->left;
            curr->left=NULL;
            TreeNode* prev=NULL;
            while(curr!=NULL){
                if(curr->left) flatten(curr); // Recursion
                prev=curr;
                curr=curr->right;
            }
            prev->right=temp;
            flatten(prev); // Recursion
        }
        else {
            flatten(curr->right); // Recursion
        }
    }
};

// Approach 1 
class Solution {
public:
    TreeNode* prev=NULL;
    void flatten(TreeNode* root) {
        if(!root) return;
        flatten(root->right);
        flatten(root->left);
        root->right=prev;
        root->left=NULL;
        prev=root;
    }
};

// Approach 2 
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return ;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* temp=st.top();
            st.pop();
            if(temp->right){
                st.push(temp->right);
            }
            if(temp->left){
                st.push(temp->left);
            }
            temp->right=st.empty()? NULL:st.top();
            temp->left=NULL;
        }
    }
};

// Approach 3
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr=root;
        while(curr){
            if(curr->left){
                TreeNode* leftChild=curr->left;
                while(leftChild->right){
                    leftChild=leftChild->right;
                }
                leftChild->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
            }
            curr=curr->right;
        }
    }
};
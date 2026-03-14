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

// This is the recursive solution 
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preOrder(root,ans);
        return ans;
    }

    void preOrder(TreeNode* root,vector<int>& ans){
        if(root==NULL) return;
        ans.push_back(root->val);
        preOrder(root->left,ans);
        preOrder(root->right,ans);
    }
};

// but they wanted iterative solution after spending 1hr or something i was able to solve
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        if(root==NULL) return {};
        st.push(root);
        while(!st.empty()){
            TreeNode* temp=st.top();
            st.pop();
            ans.push_back(temp->val);
            if(temp->right){
                st.push(temp->right);
            }
            if(temp->left){
                st.push(temp->left);
            }
        }
        return ans;
    }
};

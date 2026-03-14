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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postOrder(root,ans);
        return ans;
    }
    void postOrder(TreeNode* root,vector<int>& ans){
        if(!root) return;
        postOrder(root->left,ans);
        postOrder(root->right,ans);
        ans.push_back(root->val);
    }
};
 
// Two stack solution but the stack s2 can be replaced with the final vector ans and reverse it
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        vector<int> ans;
        if(root)  s1.push(root);
        while(!s1.empty()){
            TreeNode* temp=s1.top();
            s1.pop();
            if(temp->left){
                s1.push(temp->left);
            }
            if(temp->right){
                s1.push(temp->right);
            }
            s2.push(temp);
        }
        while(!s2.empty()){
            ans.push_back(s2.top()->val);
            s2.pop();
        }
        return ans;
    }
};

// This is a one stack solution by striver (This should be by hearted ig )
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        TreeNode* node=root;
        while(node!=NULL || !st.empty()){
            if(node){
                st.push(node);
                node=node->left;
            }
            else {
                TreeNode* temp=st.top()->right;
                if(temp==NULL){
                    temp=st.top();
                    st.pop();
                    ans.push_back(temp->val);
                    while(!st.empty() && st.top()->right==temp){
                        temp=st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                }
                else 
                    node=temp;
            }
        }
        return ans;
    }
};
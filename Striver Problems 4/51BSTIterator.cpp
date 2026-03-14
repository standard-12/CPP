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
// I solved it on my own but after seeing Stack in the Topics

class BSTIterator {
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
        putLefts(root);
    }
    void putLefts(TreeNode* curr){
       if(!curr) return;
       st.push(curr);
       while(curr->left){
            curr=curr->left;
            st.push(curr);
        }
    }
    int next() {
        TreeNode* temp=st.top();
        st.pop();
        putLefts(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
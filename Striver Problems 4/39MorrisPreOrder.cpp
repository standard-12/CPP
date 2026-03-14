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
// This was my solution this pushes either when there is no left sub tree or when there is no link
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr=root;
        while(curr){
            TreeNode* rightLeaf=getRight(curr->left,curr);
            if(!rightLeaf || (rightLeaf && rightLeaf->right==NULL)) ans.push_back(curr->val);
            if(rightLeaf && rightLeaf->right==NULL){
                rightLeaf->right=curr;
                curr=curr->left;
            }
            else {
                if(rightLeaf) rightLeaf->right=NULL;
                curr=curr->right;
            }
        }
        return ans;
    }

    TreeNode* getRight(TreeNode* curr,TreeNode* root){
        if(!curr) return NULL;
        while(curr->right!=NULL && curr->right!=root){
            curr=curr->right;
        }
        return curr;
    }
};

// This is chatgpt same thing but looks cleaner ig idk , even my solution is aesthetic
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    TreeNode* curr = root;

    while(curr){
        if(curr->left == NULL){
            ans.push_back(curr->val);
            curr = curr->right;
        }
        else{
            TreeNode* pred = curr->left;

            while(pred->right && pred->right != curr)
                pred = pred->right;

            if(pred->right == NULL){
                pred->right = curr;
                ans.push_back(curr->val); // This is the only one line change 
                curr = curr->left;
            }
            else{
                pred->right = NULL;
                
                curr = curr->right;
            }
        }
    }

    return ans;
}
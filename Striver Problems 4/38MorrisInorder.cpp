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
// I solved it on my own after getting to knoe that in morris traversal we should only move to right 
// this is only curr=curr-> right initially i had thought if right then move right else move left 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr=root;
        while(curr){
            TreeNode* rightLeaf=getRight(curr->left,curr);
            if(rightLeaf && rightLeaf->right==NULL){
                rightLeaf->right=curr;
                curr=curr->left;
            }
            else if(rightLeaf && rightLeaf->right==curr){ // else if and else can be combined see the below solution 
                rightLeaf->right=NULL;
                ans.push_back(curr->val);
                curr=curr->right;
                continue;
            }
            else {
                ans.push_back(curr->val);
                curr=curr->right;
            }
        }
        return ans;
    }

    TreeNode* getRight(TreeNode* curr,TreeNode* root){
        if(!curr) return NULL;
        while(curr->right!=NULL && curr->right!=root){ // Return the right most node
            curr=curr->right;
        }
        return curr;
    }
};

// The more compact solution 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr=root;
        while(curr){
            TreeNode* rightLeaf=getRight(curr->left,curr);
            if(rightLeaf && rightLeaf->right==NULL){
                rightLeaf->right=curr;
                curr=curr->left;
            }
            else {
                if(rightLeaf) rightLeaf->right=NULL;
                ans.push_back(curr->val);
                curr=curr->right;
                continue;
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

// The more readable solution 
vector<int> inorderTraversal(TreeNode* root) {
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
                curr = curr->left;
            }
            else{
                pred->right = NULL;
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
    }

    return ans;
}
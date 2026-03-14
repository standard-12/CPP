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

// Yeeeee i solved this on my own and it was not easy 
class Solution {
    int ind=1; // Global tracker for index in preorder
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root=new TreeNode(preorder[0]);  
        rec(root,INT_MAX,preorder); // INT_MAX for the right subtree
        return root;
    }

    void rec(TreeNode* root,int maxi,vector<int>& preorder){
        if(ind>=preorder.size() || preorder[ind]>=maxi || !root) return;
        if(preorder[ind]<root->val){
            root->left=new TreeNode(preorder[ind]);
            ind++;
            rec(root->left,root->val,preorder); // Update maxi when going to left
        }
        if(ind<preorder.size() && preorder[ind]>root->val && preorder[ind]<maxi){ // Check again because ind would have been changed here when it reaches here
            root->right=new TreeNode(preorder[ind]);
            ind++;
            rec(root->right,maxi,preorder); // Don't update maxi when going to right
        }
    }
};

// The striver solutiond does the exact same thing as above but it is more readable 
// I have always faced difficulties with recursions which have a return type and to decide on return type of recursion functions

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        int ind=0;
        return build(n,preorder,ind,INT_MAX);
    }

    TreeNode* build(int n,vector<int>& preorder,int& ind,int maxi){
        if(ind>=n || preorder[ind]>=maxi) return NULL;
        TreeNode* root=new TreeNode(preorder[ind++]);
        root->left=build(n,preorder,ind,root->val);
        root->right=build(n,preorder,ind,maxi);
        return root;
    }
};
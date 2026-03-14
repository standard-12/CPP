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
// This was my solution before knowing inorder traversal gives sorted array 
// Time Complexity O(nlogn) Space Complexity(O(n))
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int> pq;
        traverse(root,pq);
        while(pq.size()>k){
            pq.pop();
        }

        return pq.top();
    }
    void traverse(TreeNode* root,priority_queue<int>& pq){
        if(!root) return ;
        pq.push(root->val);
        traverse(root->left,pq);
        traverse(root->right,pq);
    }
};
// This is the inorder solution 
// Time Complexity O(k) Space Complexity O(k)
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inorder;
        bool b=inorderT(root,inorder,k);
        return inorder[k-1];
    }
    bool inorderT(TreeNode* root,vector<int>& inorder,int k){
        if(!root) return true;
        if(inorder.size()==k) return false;
        if(!inorderT(root->left,inorder,k)) return false;
        inorder.push_back(root->val);
        if(!inorderT(root->right,inorder,k)) return false;
        return true; 
    }
};
// This is another optimization for above solution 
// Time Complexity O(k) Space Complexity O(1)
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        // vector<int> inorder;
        int cnt=0;
        int ans=0;
        bool b=inorderT(root,ans,cnt,k);
        return ans;
    }
    bool inorderT(TreeNode* root,int& ans,int& cnt,int k){
        if(!root) return true;
        if(!inorderT(root->left,ans,cnt,k)) return false;
        
        if(++cnt==k) {
            ans=root->val;
            return false;
        }

        if(!inorderT(root->right,ans,cnt,k)) return false;
        return true; 
    }
};
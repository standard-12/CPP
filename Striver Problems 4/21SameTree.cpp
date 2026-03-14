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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return traverseTwo(p,q);
    }

    bool traverseTwo(TreeNode* p,TreeNode* q){
        if(!p && !q) return true;
        if(!p || !q) return false;
        if(p->val != q->val) return false;
        if(!traverseTwo(p->left,q->left)) return false; // See the change here
        if(!traverseTwo(p->right,q->right)) return false; // And here
        return true;
    } 
};
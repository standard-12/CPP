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

// This was my solution but this is not the optimal solution this has a worst case of O(n)
class Solution {
public:
    int countNodes(TreeNode* root) {
        int height=0;
        int count=0;
        if(!root) return 0;
        bool b=traverse(root,height,count,0);
        return (pow(2,height)-1)+count;
    }

    bool traverse(TreeNode* root,int& height,int& count,int row){
        if(!root->left && !root->right) {
            if(height==0) {
                height=row;
                count++;
                return true;
            }
            if(height==row) {
                count++;
                return true;
            }
            else return false;
        }
        if(root->left && !traverse(root->left,height,count,row+1)) return false;
        if(root->right && !traverse(root->right,height,count,row+1)) return false;
        return true;
    }
};

// This is the optimal solution, worst case of this is O((logn)^2)

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;

        int lh=leftHeight(root->left);
        int rh=rightHeight(root->right);

        if(lh==rh) return pow(2,lh)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }

    int leftHeight(TreeNode* root){
        int count=1;
        while(root){
            count++;
            root=root->left;
        }
        return count;
    }

    int rightHeight(TreeNode* root){
        int count=1;
        while(root){
            count++;
            root=root->right;
        }
        return count;
    }
};


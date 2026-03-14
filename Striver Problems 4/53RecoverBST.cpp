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

// I could solve this on my own and this is my first solution
// Time Complexity O(2n) Space Complexity O(2n)+O(logn)
class Solution {
    vector<pair<int,TreeNode*>> inorder;
public:
    void recoverTree(TreeNode* root) {
        rec(root);
        int v1=0,v2=0;
        TreeNode* node1,*node2;
        int n=inorder.size();
        for(int i=1;i<n;i++){
            if(inorder[i].first < inorder[i-1].first){
                v1=inorder[i].first;
                node1=inorder[i].second;
            }
            if(inorder[n-i-1]>inorder[n-i]){
                v2=inorder[n-i-1].first;
                node2=inorder[n-i-1].second;
            }
        }
        node1->val=v2;
        node2->val=v1;
    }

    void rec(TreeNode* curr){
        if(!curr) return;
        rec(curr->left);
        inorder.push_back({curr->val,curr});
        rec(curr->right);
    }
};

// This is the bettet solution
// Time Complexity O(2*n) Space Complexity O(logn) or O(1)(if we ignore stack space)

class Solution {
    int prev;
    TreeNode *node1=NULL,*node2=NULL;
public:
    void recoverTree(TreeNode* root) {
        prev=INT_MIN;
        inorderRec(root);
        prev=INT_MAX;
        reverseInorderRec(root);
        if(node1 && node2){
            int temp=node1->val;
            node1->val=node2->val;
            node2->val=temp;
        }
    }

    void inorderRec(TreeNode* curr){
        if(!curr) return;
        inorderRec(curr->left);
        if(curr->val<prev){
               node1=curr;
        }
        prev=curr->val;
        inorderRec(curr->right);
    }

    void reverseInorderRec(TreeNode* curr){
        if(!curr) return;
        reverseInorderRec(curr->right);
        if(curr->val>prev){
            node2=curr;
        }
        prev=curr->val;
        reverseInorderRec(curr->left);
    }
};

// This is the most optimal solution 
// TIme Complexity O(n) Space Complexity O(logn)

class Solution {
    TreeNode *prev=NULL,*first=NULL,*middle=NULL,*last=NULL;
public:
    void recoverTree(TreeNode* root) {
        inorderRec(root);
        if(first && last){
            int temp=first->val;
            first->val=last->val;
            last->val=temp;
        }
        else if(first && middle){
            int temp=first->val;
            first->val=middle->val;
            middle->val=temp;           
        }
    }

    void inorderRec(TreeNode* curr){
        if(!curr) return;
        inorderRec(curr->left);
        if(prev && (curr->val < prev->val)){
               if(!first && !middle){
                 first=prev;
                 middle=curr;
               }
               else {
                 last=curr;
               }
        }
        prev=curr;
        inorderRec(curr->right);
    }
};

// Above solution Uses this idea
// Three cases for inorder traversal :
// case 1 : All are in ascending order
// No need to do anything
// example - [1, 2, 3, 4, 5]

// case 2 : one pair is in descending order
// swap both pairs
// example - [2, 1, 3, 4, 5] <- last pointer will be null

// case 3 : two pairs are in descending order
// swap first pair's first value and second pair's second value
// example - [5, 2, 3, 4, 1] <- last pointer will be not null
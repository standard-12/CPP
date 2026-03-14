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
// Wowwwww I solved this on my OWN this had many test cases but i solved it on my own that too in first attempt good one 
// The idea is to get the leftMost child of the right Subtree of the Node to be deleted 
// Edge Cases:
//     1. What if there is no right SubTree ( But it may have leftSub Tree) ( We need to track prevDelete i.e previous of Node to be deleted)
//     2. What if the leftMost Child of right subtree has rightChild's hence we need to track previous of leftMostChild also
//     3. What if the node to be deleted is root here we should change the root while returning (Solution Check if prevDelete is NULL) 
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* curr=root;
        TreeNode* prevDelete=NULL;
        TreeNode* toDelete=NULL;
        while(curr){
            if(curr->val==key) {
                toDelete=curr;
                break;
            }
            prevDelete=curr; // This is important when the node to be deleted is root (then prev should be NULL -> so we can identify the deletion node was the root node)
            if(curr->val>key){
                curr=curr->left;
            }
            else {
                curr=curr->right;
            }
            
        }
        if(!toDelete) return root;
        cout<<toDelete->val;
        TreeNode* prev=toDelete;
        TreeNode* rightChild=toDelete->right;
        if(rightChild){  // First we check if there is rightChild then we don't need prevDelete
            while(rightChild->left){
                prev=rightChild;
                rightChild=rightChild->left;
            }
            if(prev!=toDelete) prev->left=rightChild->right;
            else prev->right=rightChild->right;
            toDelete->val=rightChild->val;
        }
        else if(prevDelete) { // If there is no rightChild we want to use prevDelete but we don't know from which side it was 
            if(prevDelete->left==toDelete){  // Check if it was left 
                prevDelete->left=toDelete->left;
            }
            else { // or right
                prevDelete->right=toDelete->left;
            }
        }
        else {  // Root is the node to be deleted
            root=toDelete->left; // We can directly do this because we are sure there is no right child hence we can directly do toDelete->left;
        }
        return root;
    }
};

// Striver has solved it in another way where he connects the whole right subTree to rightMost child of leftSubTree or 
// He connects the whole leftSubTree to leftMostChild of RightSubTree 
// Instead of Changing the values like i did 
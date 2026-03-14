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

// I couldn't solve this on my own ( I solved but it was brute force inorder traversal + normal 2 sum)
// This is the optimal Method 
// Time Complexity O(N) +Space Complexity O(2*h)
class Solution {
    stack<TreeNode*> next;
    stack<TreeNode*> before;
public:
    bool findTarget(TreeNode* root, int k) {
        putLeft(root);
        putRight(root);
        int ival=getNext();
        int jval=getBefore();
        int sum=ival+jval;

        while(ival!=jval){
            if(sum==k) return true;
            if(sum>k) {
                jval=getBefore();
            }
            else {
                ival=getNext();
            }
            sum=ival+jval;
        }
        return false;
    }

    int getNext(){
        TreeNode* temp=next.top();
        next.pop();
        putLeft(temp->right);
        return temp->val;
    }
    
    int getBefore(){
        TreeNode* temp=before.top();
        before.pop();
        putRight(temp->left);
        return temp->val;
    }

    void putLeft(TreeNode* curr){
        while(curr!=NULL){
            next.push(curr);
            curr=curr->left;
        }
    }

    void putRight(TreeNode* curr){
        while(curr!=NULL){
            before.push(curr);
            curr=curr->right;
        }
    }
};

// We could also reuse the last program's BST iterator class but we shouldn't create 2 classes
// Instead we should have a reverse variable in the last class and handle both cases in that 
// See below

// This class is an iterator for traversing the BST
class BSTIterator {
private:
    // A stack is used to keep track of nodes while traversing
    stack<TreeNode*> myStack;
    // This flag tells whether we are moving forward (inorder) or backward (reverse inorder)
    bool reverse;

public:
    // Constructor initializes the iterator with the root node and traversal direction
    BSTIterator(TreeNode* root, bool isReverse) : reverse(isReverse) {
        // Push all nodes on one side (left or right) into the stack
        pushAll(root);
    }

    // This function checks if there are more nodes left to visit
    bool hasNext() {
        // If the stack is not empty, there are still nodes left
        return !myStack.empty();
    }

    // This function returns the next node’s value in the chosen order
    int next() {
        // Get the node on top of the stack
        TreeNode* tmpNode = myStack.top();
        // Remove this node from the stack
        myStack.pop();

        // If we are not in reverse mode, we need to go right after visiting a node
        if (!reverse) {
            pushAll(tmpNode->right);
        }
        // If we are in reverse mode, we need to go left after visiting a node
        else {
            pushAll(tmpNode->left);
        }

        // Return the value of the node that was just visited
        return tmpNode->val;
    }

private:
    // This helper function pushes all nodes from the current node down to the left/right edge
    void pushAll(TreeNode* node) {
        // Keep going until we reach a null node
        while (node != nullptr) {
            // Push the node onto the stack
            myStack.push(node);
            // If reverse is true, move to the right child
            if (reverse) {
                node = node->right;
            }
            // Otherwise, move to the left child
            else {
                node = node->left;
            }
        }
    }
};

// This class contains the solution logic to check if a target sum exists in BST
class Solution {
public:
    // This function checks if two nodes in BST sum to k
    bool findTarget(TreeNode* root, int k) {
        // If tree is empty, return false immediately
        if (!root) return false;

        // Create two iterators: one for smallest-to-largest order, another for largest-to-smallest
        BSTIterator l(root, false);
        BSTIterator r(root, true);

        // Get first values from both ends
        int i = l.next();
        int j = r.next();

        // Loop until the two pointers meet
        while (i < j) {
            // If the two numbers add up to k, we found a pair
            if (i + j == k) return true;
            // If sum is too small, move left iterator forward
            else if (i + j < k) i = l.next();
            // If sum is too large, move right iterator backward
            else j = r.next();
        }

        // If no pair found, return false
        return false;
    }
};
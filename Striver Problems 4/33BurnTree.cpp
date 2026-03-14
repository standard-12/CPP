#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// This is the Optimal Solution 

class Solution {
  public:
    int minTime(Node* root, int target) {
        // code here
        unordered_map<Node*,Node*> mp;
        queue<Node*> qu;
        qu.push(root);
        mp[root]=NULL;
        while(!qu.empty()){
            int size=qu.size();
            Node* node=qu.front();qu.pop();
                if(node->left){
                    Node* leftChild=node->left;
                    mp[leftChild]=node;
                    qu.push(leftChild);
                }
                if(node->right){
                    Node* rightChild=node->right;
                    mp[rightChild]=node;
                    qu.push(rightChild);
                }
        }
        int ans=INT_MIN;
        unordered_set<Node*> st;
        Node* treeNode=findTarget(root,target);
        recur(treeNode,mp,ans,st,0);
        return ans;
    }
    
    Node* findTarget(Node* root,int target){
        if(!root) return NULL;
        if(root->data==target) return root;
        
        Node* left=findTarget(root->left,target);
        if(left) return left;
        Node* right=findTarget(root->right,target);
        if(right) return right;
        
        return NULL;
    }
    
    void recur(Node* target,unordered_map<Node*,Node*>& mp,int& ans,unordered_set<Node*>& st,int dist){
            if(!target) return;
            if(st.count(target)) return;
            st.insert(target);
            ans=max(ans,dist);
            recur(target->left,mp,ans,st,dist+1);
            recur(target->right,mp,ans,st,dist+1);
            recur(mp[target],mp,ans,st,dist+1);
        }
};
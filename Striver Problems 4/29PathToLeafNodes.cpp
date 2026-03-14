#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

// I solved this on my own this was easy 
class Solution {
  public:
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> ans;
        vector<int> temp;
        temp.push_back(root->data);
        traverse(root,temp,ans);
        return ans;
    }
    
    void traverse(Node* root,vector<int>& temp,vector<vector<int>>& ans){
        if(!root) return;
        if(!root->left && !root->right){
            ans.push_back(temp);
            return;
        }
        if(root->left){
            temp.push_back(root->left->data);
            traverse(root->left,temp,ans);
            temp.pop_back();
        }
        if(root->right){
            temp.push_back(root->right->data);
            traverse(root->right,temp,ans);
            temp.pop_back();
        }

    }
};
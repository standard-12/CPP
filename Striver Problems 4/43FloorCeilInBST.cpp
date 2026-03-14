#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
  public:
    int findCeil(Node* root, int x) {
        // code here
        Node* curr=root;
        int ans=INT_MAX;
        while(curr){
            if(curr->data==x) return curr->data;
            if(curr->data>x) ans=min(ans,curr->data);
            if(curr->data<x) curr=curr->right;
            else curr=curr->left;
        }
        return ans!=INT_MAX? ans:-1;
    }
};
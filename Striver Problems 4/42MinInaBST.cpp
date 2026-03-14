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
    int minValue(Node* root) {
        // code here
        if(!root) return 0;
        Node* curr=root;
        while(curr->left){
            curr=curr->left;
        }
        return curr->data;
    }
};
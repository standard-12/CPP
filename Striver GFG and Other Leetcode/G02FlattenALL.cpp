#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

class Solution {
  public:
    Node *flatten(Node *root) {
        // code here
            Node* temp=root;
            return flat(root);
        
    }
    Node* flat(Node* root){
        if(!root || !root->next) return root;
        root->next=flat(root->next);
        return merge(root,root->next);
        
    }
    Node* merge(Node* l1,Node* l2){
        Node dummy(0);
        Node* temp=&dummy;
        while(l1!=NULL && l2!=NULL){
            if(l1->data < l2->data){
                temp->bottom=l1;
                l1=l1->bottom;
                temp=temp->bottom;
            }
            else {
                temp->bottom=l2;
                l2=l2->bottom;
                temp=temp->bottom;
            }
            temp->next=NULL;
        }
        if(l1) temp->bottom=l1;
        else temp->bottom=l2;
        return dummy.bottom;
    }
};
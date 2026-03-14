#include<iostream>
#include<stdio.h>
using namespace std;

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}node;

node* root=NULL;

node* createnewnode(int data){
    node* temp= new node;
    temp->data=data;
    temp->left=temp->right=NULL;
}

node* insert(node* root,int data){
    if(root==NULL){
      root=createnewnode(data);
    }
    else if(data<root->data){
      root->left=insert(root->left,data);  
    }
    else{
        root->right=insert(root->right,data);
    }
    return root;
}






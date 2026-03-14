#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

// this was my own solution actually there is no need to handle last node manually we can do it as (See below)
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        Node* temp=head;
        Node* tptr;
        while(temp->next!=NULL){
            tptr=temp->prev;
            temp->prev=temp->next;
            temp->next=tptr;
            temp=temp->prev;// Since its interchanged;
        }
        //change last node manually
        temp->next=temp->prev;
        temp->prev=NULL; 
        head=temp; // instead of handling last node manually we can do if(tptr) head=tptr->prev; since this teporary variable has the node before the last node
        return head;
    }
};
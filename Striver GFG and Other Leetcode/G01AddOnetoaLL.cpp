#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};


class Solution {
  public:
    Node* addOne(Node* head) {
        // Your Code here
        Node* h=reverse(head);
        Node* t=h;
        int carry=1;
        while(carry!=0){
              int val=t->data+carry;
              carry=(val/10);
              t->data=val%10;
              if(carry==0) return reverse(h);
              else if(!t->next) t->next=new Node(0);
              t=t->next;
        }
        return reverse(h);
        // return head of list after adding one
    }
    Node* reverse(Node* head){
        if(!head || !head->next) return head;
        Node* temp=head;
        Node* prev=NULL;
        while(temp!=NULL){
            Node* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        head=prev;
        return head;
    }
};

// The Above solution is O(3n)
// So we use recursion which does O(n) but has stack frame space complexity of O(n) 
// And i came up on my own with this recursion 
class Solution {
  public:
    Node* addOne(Node* head) {
        // Your Code here
        int carry= recursive_addition(head);
        if(carry){
            Node* temp=new Node(1);
            temp->next=head;
            head=temp;
        }
        return head;
        // return head of list after adding one
    }
    int recursive_addition(Node* head){
        if(head==NULL) return 1;
        int carry=recursive_addition(head->next);
        int val=head->data+carry;
        carry=val/10;
        head->data=val%10;
        return carry;
    }
};
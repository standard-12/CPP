#include<bits/stdc++.h>
using namespace std;
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

// I came up with this solution on my own
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        Node arr[3]={0,0,0};
        Node* ptr[3];
        for(int i=0;i<3;i++){
            ptr[i]=&arr[i];
        }
        Node* temp=head;
        while(temp!=NULL){
            int val=temp->data;
            ptr[val]->next=temp;
            ptr[val]=ptr[val]->next;
            temp=temp->next;
        }
        ptr[0]->next=arr[1].next? arr[1].next:arr[2].next;
        ptr[1]->next=arr[2].next;
        ptr[2]->next=NULL;
        Node* newhead;
        if(arr[0].next)
            newhead=arr[0].next;
        else if(arr[1].next)
            newhead=arr[1].next;
        else 
            newhead=arr[2].next;
         return newhead;
        // Here i can just retur arr[0].next without any checks because of how we link ptr[0].next
        // So last 3 checks are redundant and directly returning arr[0].next works
    }
};
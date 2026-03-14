#include<bits/stdc++.h>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// This was written by me on my own though i couldnt come up with recursion on my own 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp=head;
        ListNode* prev=NULL;
        ListNode* tptr;
        while(temp!=NULL){
            tptr=temp->next;
            temp->next=prev;
            prev=temp;
            temp=tptr;
        }
        head=prev;
        return head;
    }
};

// Recursion 

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        return reverse(head);
    }
    ListNode*  reverse(ListNode* n){
        if(!n || !n->next){
            return n;
        }
        ListNode* newHead=reverse(n->next);

        n->next->next=n;
        n->next=NULL;
        return newHead;
    }
};
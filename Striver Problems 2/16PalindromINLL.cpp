#include<bits/stdc++.h>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
// This was my code after seeing the discussion
 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* temp=fast==NULL? reverse(slow):reverse(slow->next);
        slow=head;
        while(temp!=NULL){
            if(slow->val!=temp->val) return false;
            slow=slow->next;
            temp=temp->next;
        }
        return true;
    }
    ListNode* reverse(ListNode* p){
        ListNode* t=p;
        ListNode* prev=NULL;
        ListNode* front;
        while(t!=NULL){
            front=t->next;
            t->next=prev;
            prev=t;
            t=front;
        }
        return prev;
    }
};

// few small correction for better 

 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        if (!head || !head->next) return true; // should add this since we are modifying the while condition
        while(fast->next!=NULL && fast->next->next!=NULL){ // use fast->next->next instead fo fast!=NULL so no ternary required 
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* temp=reverse(slow->next); // because of the above correction ternary not required here;
        ListNode* newhead=temp;// copy for reversing later
        slow=head;
        while(temp!=NULL){
            if(slow->val!=temp->val){ 
                reverse(newhead); // reset like before
                return false;
            }
            slow=slow->next;
            temp=temp->next;
        }
        reverse(newhead); // reset like before
        return true;
    }
    ListNode* reverse(ListNode* p){
        ListNode* t=p;
        ListNode* prev=NULL;
        ListNode* front;
        while(t!=NULL){
            front=t->next;
            t->next=prev;
            prev=t;
            t=front;
        }
        return prev;
    }
};
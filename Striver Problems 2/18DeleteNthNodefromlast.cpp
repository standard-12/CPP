#include<bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
// This is the optimal O(n) solution
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode* fast=head;
       ListNode* slow=head;
       for(int i=0;i<n;i++) fast=fast->next;
       if(fast==NULL){
            ListNode* temp=head->next;
            delete head;
            head=temp;
       } 
       else {
            while(fast->next!=NULL){
                slow=slow->next;
                fast=fast->next;
            }
            ListNode* temp=slow->next;
            slow->next=temp->next;
            delete temp;
       }
       return head;
    }
};
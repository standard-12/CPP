#include<bits/stdc++.h>
using namespace std;
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

// I solved it on my own
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        ListNode* fast=head;
        ListNode* slow=head;
        int len=0;
        while(fast!=NULL){
            fast=fast->next;
            len++;
        }
        fast=head;
        int t=k%len;
        if(t==0) return head;
        while(t>0){
            fast=fast->next;
            t--;
        }
        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        fast->next=head;
        head=slow->next;
        slow->next=NULL;
        return head;
    }
};
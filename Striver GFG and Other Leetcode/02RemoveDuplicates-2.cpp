#include<bits/stdc++.h>
using namespace std;

// LC 82
  struct ListNode {
      int val;
     ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

 // hurray i came up with the optimal solution;
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode node;
        ListNode* dummy=&node;
        ListNode* temp=head;
        while(temp!=NULL){
            if(temp->next && temp->val == temp->next->val ){
                int tempval=temp->val;
                while(temp!=NULL && temp->val==tempval){             
                 temp=temp->next;
                }
            }
            else {
                dummy->next=temp;
                dummy=dummy->next;
                temp=temp->next;
            }
        }
        dummy->next=NULL;
        return node.next;
        
    }
};
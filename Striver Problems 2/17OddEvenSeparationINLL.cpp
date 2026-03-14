#include<bits/stdc++.h>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

// Hurray i came up with this solution on my own
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* odd=head;
        ListNode* even=head->next;
        ListNode* copy=even;// To connect at last;
        while(odd!=NULL && even!=NULL){ // or it can just be written while(even && even->next)
            if(even->next==NULL) break; // and if could be reomved
            odd->next=even->next;
            odd=odd->next;
            even->next=odd->next;
            even=even->next;
        }
        odd->next=copy;
        return head;
    }
};
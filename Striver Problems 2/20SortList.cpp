#include<bits/stdc++.h>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* mid=findMiddle(head);
        ListNode* right=mid->next;
        mid->next=NULL;
        ListNode* l1=sortList(head);
        ListNode* l2=sortList(right);
        return mergeList(l1,l2);
    }
    ListNode* findMiddle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;// To make the head stop at first mid in even number case
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    ListNode* mergeList(ListNode* list1,ListNode* list2){
        ListNode dummy;
        ListNode* temp=&dummy;
        while(list1!=NULL && list2!=NULL){
            if(list1->val<=list2->val){
                temp->next=list1;
                list1=list1->next;
                temp=temp->next;
            }
            else {
                temp->next=list2;
                list2=list2->next;
                temp=temp->next;
            }
        }
        temp->next=list1==NULL? list2:list1;
        return dummy.next;
    }

};

// There is complete O(1) solution which doesn't even use O(logn) stack space
// The iterative method
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head; // 0 or 1 element, already sorted

        int length = getLength(head);          // total number of nodes
        ListNode dummy(0);                     // dummy node to simplify head handling
        dummy.next = head;

        // step = size of sublists to merge: 1, 2, 4, 8, ...
        for (int step = 1; step < length; step <<= 1) {
            ListNode* prev = &dummy;           // tail of the merged list so far
            ListNode* curr = dummy.next;       // current node to process

            while (curr) {
                // Split off two sublists of size "step"
                ListNode* left  = curr;
                ListNode* right = split(left, step);   // right half starts here
                curr = split(right, step);             // next pair starts here

                // Merge the two sorted halves
                prev->next = merge(left, right);

                // Move prev pointer to the end of merged sublist
                while (prev->next) prev = prev->next;
            }
        }

        return dummy.next;
    }

private:
    // Count the total number of nodes
    int getLength(ListNode* head) {
        int len = 0;
        while (head) {
            ++len;
            head = head->next;
        }
        return len;
    }

    // Split the list into two parts:
    // first 'n' nodes, and the rest.
    // Returns the head of the second part.
    ListNode* split(ListNode* head, int n) {
        while (--n && head) {
            head = head->next;
        }
        if (!head) return nullptr;

        ListNode* second = head->next;
        head->next = nullptr;  // cut the list
        return second;
    }

    // Merge two sorted linked lists into one sorted list
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        // Attach the remainder (only one of l1, l2 is non-null)
        tail->next = l1 ? l1 : l2;

        return dummy.next;
    }
};
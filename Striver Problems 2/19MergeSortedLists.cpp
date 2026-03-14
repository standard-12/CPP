#include<bits/stdc++.h>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

// this was my own solution without any help i am proud i could come up with the trick of recursive swap at starting
// This just uses the nodes given but there is a simpler approach with dummy node
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        if(list2->val < list1->val) return mergeTwoLists(list2,list1);
        ListNode* l1=list1;
        ListNode* l2=list2;
        ListNode* t1=NULL;
        ListNode* t2=NULL;
        while(l1!=NULL && l2!=NULL){
            if(l1->val<=l2->val && (l1->next==NULL || l1->next->val>=l2->val)){
                t1=l1->next;
                l1->next=l2;
                l2=l2->next;
                if(l1->next) l1->next->next=t1;
            }
            l1=l1->next;
        }
        return list1;
    }
};

//The easy to understand and also preferred solution
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy;              // sentinel node
        ListNode* tail = &dummy;     // tail pointer to build result

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        // Attach whatever remains
        tail->next = list1 ? list1 : list2;

        return dummy.next;
    }
};

// There is a nice rexursive solution which is good for smaller lists
// i saw this to improve my recursion
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;

        if (list1->val <= list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};

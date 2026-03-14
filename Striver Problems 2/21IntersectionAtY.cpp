#include<bits/stdc++.h>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };


 //This was my solution 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* one=headA;
        ListNode* two=headB;
        bool b=false;
        while(one!=NULL && two!=NULL){
            one=one->next;
            two=two->next;
        }
        if(one==NULL) b=true;  // i.e first list reached first
        int count=0;
        while(one!=NULL || two!=NULL){
            if(one) one=one->next;
            if(two) two=two->next;
            count++;
        }
        one=headA;two=headB;
        int k=0;
        while(k<count){
            if(b) two=two->next; // one had reached first 
            else one=one->next;
            k++;
        }
        while(one!=NULL &&  two!=NULL){
            if(one==two) break;
            one=one->next;
            two=two->next;
        }
        return one;
    }
};

// This is the best solution
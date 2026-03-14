#include<bits/stdc++.h>
using namespace std;

 struct ListNode {
     int val;
      ListNode *next;
     ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

// This was my solution this works for small inputs but blows up for large linkedlists containg 100 nodes etc since even long long cannot hold the value
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=l1;
        long long mul1=1;
        long long val1=0,val2=0;
        while(temp1!=NULL){
            val1+=mul1*temp1->val;
            mul1*=10;
            temp1=temp1->next;
        }
        mul1=1; temp1=l2;
        while(temp1!=NULL){
            val2+=mul1*temp1->val;
            mul1*=10;
            temp1=temp1->next;        
        }
        val1=val1+val2;
        if(val1==0) return new ListNode(0);
        ListNode* prev=NULL; 
        ListNode* newhead=NULL;
        while(val1>0){
            ListNode* temp2=new ListNode();
            int digit=val1%10;
            val1=val1/10;
            if(prev) {
                prev->next=temp2;
            }
            else {
                newhead=temp2;
            }
            prev=temp2;
            temp2->val=digit;
            temp2->next=NULL;
        }
        return newhead;
    }
};
// I solved the problem in my own after getting to know about dummyNode Approach but my solution was not fully clear 
// I used separate if case for adding carry at the end if any remained, and i mutated existing lists
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* temp=&dummy;
        temp->next=l2;
        temp=temp->next;
        int carry=0;
        while(temp!=NULL){
            int val1=l1? l1->val:0;
            int val2=l2? l2->val:0;
            int sum=val1+val2+carry;
            carry=sum>=10? 1:0;
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
            temp->val=sum%10;
            temp->next=l2? l2:l1;
            if(temp->next==NULL && carry==1){
                temp->next=new ListNode(carry);
                break;
            }
            temp=temp->next;
        }
        return dummy.next;
    }
};
// This is the optimal solution which also take cares of carry node at last without any separate edge case for it
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);   // dummy head
        ListNode* curr = &dummy;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int val1 = (l1 ? l1->val : 0);
            int val2 = (l2 ? l2->val : 0);
            int sum = val1 + val2 + carry;

            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        return dummy.next;
    }
};

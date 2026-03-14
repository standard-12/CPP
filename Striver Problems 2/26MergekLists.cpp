#include<bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// This was my first solution
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size=lists.size();
        if(size==0) return NULL; 
        for(int i=size-2;i>=0;i--){
            lists[i]=merge(lists[i],lists[i+1]);
        }
        return lists[0];
    }
    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode dummy(0);
        ListNode* temp=&dummy;
        while(l1!=NULL && l2!=NULL){
            if(l1->val <= l2->val){
                temp->next=l1;
                l1=l1->next;
                temp=temp->next;
            }
            else {
                temp->next=l2;
                l2=l2->next;
                temp=temp->next;
            }
        }
        temp->next=l1? l1:l2;
        return dummy.next;
    }
};
// This was my second solution
// This is not taking advantage of each lists being sorted
// But this worked well but not the expected solution
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size=lists.size();
        if(size==0) return NULL; 
        ListNode dummy;
        ListNode* dptr=&dummy;
        for(int i=0;i<size;i++){
            dptr->next=lists[i];
            while(dptr->next!=NULL){
                dptr=dptr->next;
            }
        }
        return mergesort(dummy.next);
    }
    ListNode* mergesort(ListNode* head){
        if(!head || !head->next) return head; 
        ListNode* slow=head;
        ListNode* fast=head;
        fast=fast->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* t=slow->next;
        slow->next=NULL;
        ListNode* left = mergesort(head);
        ListNode* right=mergesort(t);
        return merge(left,right);
    }
    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode dummy(0);
        ListNode* temp=&dummy;
        while(l1!=NULL && l2!=NULL){
            if(l1->val <= l2->val){
                temp->next=l1;
                l1=l1->next;
                temp=temp->next;
            }
            else {
                temp->next=l2;
                l2=l2->next;
                temp=temp->next;
            }
        }
        temp->next=l1? l1:l2;
        return dummy.next;
    }
};

// This is the optimal solution
// Let n=max no of nodes in any list , k=size of array of lists
// Time Complexity=O(klogk)+O(n*k*logk) Space Complexity O(k)

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
        ListNode dummy(0);
        ListNode* temp=&dummy;
        for(int i=0;i<n;i++){
            if(lists[i])
                pq.push({lists[i]->val,lists[i]});
        }
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            temp->next=p.second;
            ListNode* t=p.second->next;
            if(t){
                pq.push({t->val,t});
            }
            temp=temp->next;
        }
        return dummy.next;
    }
};

// Another solution with pair wise merge (same as above merge but nlogk);

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        int n = lists.size();
        while (n > 1) {   
            int i = 0, j = n - 1;
            while (i < j) {
                lists[i] = merge(lists[i], lists[j]);
                i++;
                j--;
            }
            n = (n + 1) / 2; // shrink the problem size
        }
        return lists[0];
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* temp = &dummy;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                temp->next = l1;
                l1 = l1->next;
            } else {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        temp->next = l1 ? l1 : l2;
        return dummy.next;
    }
};

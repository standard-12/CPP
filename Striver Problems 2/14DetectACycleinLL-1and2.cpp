#include<bits/stdc++.h>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
  };
// This is the brute force solution with O(n) space
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> mp;
        ListNode* temp=head;
        while(temp!=NULL){
            if(mp.count(temp)) return true;
            mp.insert(temp);
            temp=temp->next;
        }
        return false;
    }
};

// I had written a hacky solution with O(1) space but its just a hack not the solution
class Solution {
public:
    bool hasCycle(ListNode *head) {
        int count=1e4+1; // There was a constraint that only 10^4 nodes will be there
        ListNode* temp=head;
        while(temp!=NULL && count>0){
            temp=temp->next;
            count--;
        }
        return temp==NULL? false:true;
    }
};

// This is the preffered solution since the gap between fast and slow decreases in one one step it is 100% percent that both meet if there is a loop
// Like relative speed is one so if fast has overtaken slow and there is a loop fast will be approaching the slow one step closer everytime
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return true;
        }
        return false;
    }
};

// This is another problem where we should find the starting point of LL
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) {
                slow=head;//imp part;
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;
            }
        }
        return NULL;

    }
};
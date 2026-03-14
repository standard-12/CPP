#include<bits/stdc++.h>
using namespace std;


  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 

 // This was my Solution but this is Brute Force O(2n)
 // Optimal Solution is Torotoise and Hare method O(n)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int count=0;
        ListNode* temp=head;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        int mid=(count/2)+1;
        temp=head;
        count=0;
        while(temp!=NULL){
            count++;
            if(count==mid) return temp;
            temp=temp->next;
        }
        return NULL;
    }
};


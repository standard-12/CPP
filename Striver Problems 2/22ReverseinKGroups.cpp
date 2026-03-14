#include<bits/stdc++.h>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
// This is a hard problem in LC and i solved it on my own and its the optimal solution
// but yea it's a bit a bit messy 
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* curr=head;
        ListNode* front;
        ListNode* prev=NULL;
        bool b=true;
        int length=0;
        while(temp!=NULL){
            temp=temp->next;
            length++;
        }
        temp=head;
        int count=length/k;
        ListNode* tail=NULL;
        ListNode* prevtail;
        while(count>0){
            int t=k;
            prevtail=tail;
            tail=curr;
        while(curr!=NULL && t>0){
            front=curr->next;
            curr->next=prev;
            prev=curr;
            curr=front;
            t--;
        }
        if(b){
            head=prev;
            b=false;
        }
        else {
            prevtail->next=prev;
        }
        tail->next=curr;
        count--;
        }
        
        return head;
    }
};

// ChatGPT gave this one 
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        // Dummy node before head for easy handling of the first group
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prevGroupTail = &dummy; // Tail of the last processed group
        ListNode* curr = head;

        while (true) {
            // Check if there are k nodes left
            ListNode* node = curr;
            for (int i = 0; i < k; i++) {
                if (!node) return dummy.next; // fewer than k nodes, stop
                node = node->next;
            }

            // Reverse k nodes
            ListNode* prev = node;  // this will connect to the next group
            ListNode* tail = curr;  // original head becomes tail after reverse
            for (int i = 0; i < k; i++) {
                ListNode* front = curr->next;
                curr->next = prev;
                prev = curr;
                curr = front;
            }

            // Connect the previous group to the newly reversed one
            prevGroupTail->next = prev;
            prevGroupTail = tail;
        }
    }
};

// There is this recursive approach also which looks very clear

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* node = head;
        // Step 1: check if there are at least k nodes left
        for (int i = 0; i < k; i++) {
            if (!node) return head;  // fewer than k → return as-is
            node = node->next;
        }

        // Step 2: reverse first k nodes
        ListNode* prev = nullptr;
        ListNode* curr = head;
        for (int i = 0; i < k; i++) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        // Step 3: recurse for the rest
        head->next = reverseKGroup(curr, k);

        // prev is the new head of the reversed group
        return prev;
    }
};

// This was strivers solution vasically doing the same i didn't separate the values like for every k group i didn't do kthnode->next=NULL
// I just did a dry run in one example and made it work but this is more readable
class Node {
public:
    int data;
    Node* next;      
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Function to reverse nodes in groups of K
Node* kReverse(Node* head, int k){
    // Initialize a temporary
    // node to traverse the list
    Node* temp = head; 

    // Initialize a pointer to track the
    // ;ast node of the previous group
    Node* prevLast = NULL; 
    
    // Traverse through the linked list
    while(temp != NULL){
        // Get the Kth node of the current group
        Node* kThNode = getKthNode(temp, k); 

        // If the Kth node is NULL
        // (not a complete group)
        if(kThNode == NULL){
            // If there was a previous group,
            // link the last node to the current node
            if(prevLast){
                prevLast -> next = temp; 
            }
            
            // Exit the loop
            break; 
        }        
        // Store the next node after the Kth node
        Node* nextNode = kThNode -> next; 

        // Disconnect the Kth node to prepare for reversal
        kThNode -> next = NULL; 

        // Reverse the nodes from  temp to the Kth node
        reverseLinkedList(temp); 

        // Adjust the head if the reversal  starts from the head
        if(temp == head){
            head = kThNode;
        }else{
            // Link the last node of the previous group to the reversed group
            prevLast -> next = kThNode; 
        }
        // Update the pointer to the last node of the previous group
        prevLast = temp; 
        // Move to the next group
        temp = nextNode; 
    }
    
    // Return the head of the modified linked list
    return head; 
}

Node* reverseLinkedList(Node *head)
{
   // Initialize'temp' at head of linked list
   Node* temp = head;  
   
   // Initialize pointer 'prev' to NULL, representing the previous node
   Node* prev = NULL;  
   
   // Traverse the list, continue till 'temp' reaches the end (NULL)
   while(temp != NULL){  
       // Store the next node in 'front' to preserve the reference
       Node* front = temp->next;  
       
       // Reverse the direction of the current node's 'next' pointer to point to 'prev'
       temp->next = prev;  
       
        // Move 'prev' to the current node for the next iteration
       prev = temp;  
       
        // Move 'temp' to the 'front' node advancing the traversal
       temp = front; 
   }   
   // Return the new head of the reversed linked list
   return prev;  
}

// Function to get the Kth node from a given position in the linked list
Node* getKthNode(Node* temp, int k){
    // Decrement K as we already start from the 1st node
    k -= 1; 

    // Decrement K until it reaches the desired position
    while(temp != NULL && k > 0){
        k--;       
        temp = temp -> next; 
    }
    return temp; 
}






#include<bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
// I was simply complicating the problem the solution was very simple 
// I literally tried for 2 hrs by doing some morris traversal adding right pointer to the curr node( so we can check where is the link by
// seeing if right value is smaller (usually it's bigger but when i create a link i was creating for small so as to distinguish))
// I DIDN'T PASTE THE CODE HERE BECAUSE ITS BS
class Solution {
  public:
    Node* getRightMost(Node* curr){
        if(!curr) return NULL;
        while(curr->right){
            curr=curr->right;
        }
        return curr;
    }
    
    Node* getLeftMost(Node* curr){
        if(!curr) return NULL;
        while(curr->left){
            curr=curr->left;
        }
        return curr;
    }
    
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        vector<Node*> ans={NULL,NULL};
        Node* lessMaxi=NULL;
        Node* greatMini=NULL;
        Node* curr=root;
        while(curr){
            if(curr->data==key){
                ans[0]=!curr->left? lessMaxi:getRightMost(curr->left);
                ans[1]=!curr->right? greatMini:getLeftMost(curr->right);
                return ans;
            }
            else if(curr->data>key){
                if(!greatMini || curr->data<greatMini->data){
                    greatMini=curr;
                }
                curr=curr->left;
            }
            else {
                if(!lessMaxi || curr->data>lessMaxi->data){
                    lessMaxi=curr;
                }
                curr=curr->right;
            }
        }
        ans[0]=lessMaxi;
        ans[1]=greatMini;
        return ans;
    }

};

// The ChatGPT's Cleaner Solution 
class Solution {
public:

    Node* getRightMost(Node* curr){
        while(curr && curr->right)
            curr = curr->right;
        return curr;
    }

    Node* getLeftMost(Node* curr){
        while(curr && curr->left)
            curr = curr->left;
        return curr;
    }

    vector<Node*> findPreSuc(Node* root, int key) {

        Node* pred = NULL;
        Node* succ = NULL;
        Node* curr = root;

        while(curr){

            if(curr->data == key){
                
                if(curr->left)
                    pred = getRightMost(curr->left);

                if(curr->right)
                    succ = getLeftMost(curr->right);

                break;
            }

            else if(curr->data > key){
                succ = curr;
                curr = curr->left;
            }

            else{
                pred = curr;
                curr = curr->right;
            }
        }

        return {pred, succ};
    }
};
#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// This was my solution and the idea was proper but when i do the level order traversal the first
// element i get for a column is the topest element 
// The method i used was checking rowDepth also which is not necessary in level order but is necessary if 
// pre,post,in traversals etc

class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        map<int,pair<int,int>> mp;
        queue<pair<Node*,pair<int,int>>> qu;
        
        qu.push({root,{0,0}});
        
        while(!qu.empty()){
            pair<Node*,pair<int,int>> p=qu.front();
            qu.pop();
            Node* temp=p.first;
            int rowVal=p.second.first;
            int colVal=p.second.second;
            if(temp->left) qu.push({temp->left,{rowVal+1,colVal-1}});
            if(temp->right) qu.push({temp->right,{rowVal+1,colVal+1}});
            if(mp.count(colVal) && mp[colVal].first > rowVal) {
                mp[colVal]={rowVal,temp->data};
            }
            else if(!mp.count(colVal)){
                mp[colVal]={rowVal,temp->data};
            }
        }
        
        vector<int> ans;
        for(auto m :mp){

            ans.push_back(m.second.second);
        }
        return ans;
    }
};

// The Optimal Solution is 
class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        map<int,pair<int,int>> mp;
        queue<pair<Node*,pair<int,int>>> qu;
        
        qu.push({root,{0,0}});
        
        while(!qu.empty()){
            pair<Node*,pair<int,int>> p=qu.front();
            qu.pop();
            Node* temp=p.first;
            int rowVal=p.second.first;
            int colVal=p.second.second;
            if(temp->left) qu.push({temp->left,{rowVal+1,colVal-1}});
            if(temp->right) qu.push({temp->right,{rowVal+1,colVal+1}});
            if(!mp.count(colVal)){ // If we remove the if check then this is the solution for the BOTTOM VIEW OF THE TREE PROBLEM
                mp[colVal]={rowVal,temp->data};
            }
        }
        
        vector<int> ans;
        for(auto m :mp){

            ans.push_back(m.second.second);
        }
        return ans;
    }
};

// I just checked if the above (my idea) idea works for preorder postorder etc and it works
class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        map<int,pair<int,int>> mp;
        preOrder(root,0,0,mp);
                vector<int> ans;
        for(auto m :mp){

            ans.push_back(m.second.second);
        }
        return ans;
    }
    
    void preOrder(Node* root,int rowVal,int colVal,map<int,pair<int,int>>& mp){
        if(root==NULL) return;
        preOrder(root->left,rowVal+1,colVal-1,mp);
        preOrder(root->right,rowVal+1,colVal+1,mp);
        
        if(mp.count(colVal) && mp[colVal].first > rowVal) {
                mp[colVal]={rowVal,root->data};
            }
            else if(!mp.count(colVal)){
                mp[colVal]={rowVal,root->data};
            }
    }
};


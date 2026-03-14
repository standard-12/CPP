#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

// I couldn't solve this on my own saw striver video and later wrote code on my own but made a mistake there
// also remember u don't need for loop evertime in the level order traversal i used for loop for assgning parent 
// which was wrong the below approach is proper
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> mp;
        queue<TreeNode*> qu;
        qu.push(root);
        mp[root]=NULL;
        while(!qu.empty()){
            int size=qu.size();
            TreeNode* node=qu.front();qu.pop();
                if(node->left){
                    TreeNode* leftChild=node->left;
                    mp[leftChild]=node;
                    qu.push(leftChild);
                }
                if(node->right){
                    TreeNode* rightChild=node->right;
                    mp[rightChild]=node;
                    qu.push(rightChild);
                }
        }

        vector<int> ans;
        unordered_set<TreeNode*> vis;
        recur(target,mp,ans,vis,0,k);
        return ans;
    }
        void recur(TreeNode* target,unordered_map<TreeNode*,TreeNode*>& mp,vector<int>& ans,unordered_set<TreeNode*>& st,int dist,int k){
            if(!target) return;
            if(st.count(target)) return;
            if(dist>k) return; // This is for Optimization 
            st.insert(target);
            cout<<target->val;
            
            if(dist==k){
                ans.push_back(target->val);
            }
            recur(target->left,mp,ans,st,dist+1,k);
            recur(target->right,mp,ans,st,dist+1,k);
            recur(mp[target],mp,ans,st,dist+1,k);
        }
};
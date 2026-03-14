#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

// I COULDN'T solve this on my own and this has a very heavy use of data structures 
// There is another version using multiset which is next solution same concept but use of multiset automatically sorts it 
// And this can also be solved using inorder traversals here we used Level Order traversal ( and level order is very simple compared to other)

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int>>> mp;
        queue<pair<TreeNode*,pair<int,int>>> qu; // (TreeNode*,row,col)
        qu.push({root,{0,0}});
        while(!qu.empty()){
            auto p=qu.front();
            qu.pop();
            TreeNode* temp=p.first;
            if(temp->left) qu.push({temp->left,{p.second.first+1,p.second.second-1}});
            if(temp->right) qu.push({temp->right,{p.second.first+1,p.second.second+1}});
            mp[p.second.second][p.second.first].push_back(temp->val);
        }
        vector<vector<int>> ans;
        for(auto m : mp){
            auto secondMap=m.second;
            vector<int> vec;
            for(auto s : secondMap){
                auto& v = s.second;
                sort(v.begin(),v.end());
                for(int i=0;i<v.size();i++){
                    vec.push_back(v[i]);
                }
            }
            ans.push_back(vec);
        }
        return ans;
    }
};
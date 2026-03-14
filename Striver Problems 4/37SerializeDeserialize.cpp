#include<bits/stdc++.h>
using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

// This had new syntaxes i tried using '0'+curr->val but it only works for 0<=nums<=9 i thought i should work for any number since it will store
// ASCII values but the constraint was -1000 to 1000 so that is more than one byte so it was failing in those conditions and hence we use
// "," as a separator so we should push "," with null or the number 
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string s;
        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty()){
            int size=qu.size();
            TreeNode* temp=qu.front();qu.pop();
            if(temp==NULL){
                s+="null,";
                continue;
            }
            s+=to_string(temp->val)+',';
            qu.push(temp->left);
            qu.push(temp->right);
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        stringstream ss(data);
        string str;
        getline(ss,str,',');
        queue<TreeNode*> qu;
        TreeNode* root=new TreeNode(stoi(str));
        qu.push(root);
        while(!qu.empty()){
            TreeNode* temp=qu.front();qu.pop();
            getline(ss,str,',');
            if( str=="null"){
                temp->left=NULL;
            }
            else {
                temp->left=new TreeNode(stoi(str));
                qu.push(temp->left);
            }
            getline(ss,str,',');
            if(str=="null"){
                temp->right=NULL;
            }
            else {
                temp->right=new TreeNode(stoi(str));
                qu.push(temp->right);
            }
        }
        return root;
    }

};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
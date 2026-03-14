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

// I couldn't solve this on my own but this has a nice idea like we have to propagate the details from 
// below of the tree 
// It's like Validating a BST in ulta (the previouse isValidate BST is topDown Approach this is Bottom UP)
 
class Solution {
    class ans {
        public:
            int sum;
            int mini;
            int maxi;
            bool isBst;

            ans(int sum,int mini,int maxi,bool isBST){
                this->sum=sum;
                this->mini=mini;
                this->maxi=maxi;
                this->isBst=isBST;
            }
    };

public:
    int maxSumBST(TreeNode* root) {
        int maxi=INT_MIN;
        ans a=rec(root,maxi);
        return max(0,maxi);
    }

    ans rec(TreeNode* root,int& maxi){
        if(!root) return ans(0,INT_MAX,INT_MIN,true); // See the constructor 
        ans left=rec(root->left,maxi);
        ans right=rec(root->right,maxi);
        if(!(left.isBst && right.isBst)) return ans(0,INT_MAX,INT_MIN,false);
        if(root->val<=left.maxi || root->val>=right.mini){
            return ans(0,INT_MAX,INT_MIN,false);
        }
        else {
            int sum=left.sum+right.sum+root->val;
            int tMini=min(root->val,left.mini); // Mini of Left Not right (V.imp)
            int tMaxi=max(root->val,right.maxi); // Maxi of right Not left (V.imp)
            maxi=max(maxi,sum);
            return ans(sum,tMini,tMaxi,true);
        }
        return ans(0,0,0,true);//dummy
    }
};
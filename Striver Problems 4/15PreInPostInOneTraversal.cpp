#include <bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// This solution is also not intuitve and should be by hearted if needed
class Solution {
public:
    vector<vector<int>> preInPostTraversal(Node* root) {
        vector<int> pre, in, post;
        stack<pair<Node*, int>> st;

        if (root == NULL) {
            return {};
        }
        
        st.push({root, 1});

        while (!st.empty()) {
            auto it = st.top();
            st.pop();

            if (it.second == 1) {
                // Store the node's data in the preorder traversal
                pre.push_back(it.first->data);
                // Move to state 2 (inorder) for this node
                it.second = 2;
                // Push the updated state back onto the stack
                st.push(it); 

                // Push left child onto the stack for processing
                if (it.first->left != NULL) {
                    st.push({it.first->left, 1});
                }
            }

            // this is a part of in
            else if (it.second == 2) {
                // Store the node's data in the inorder traversal
                in.push_back(it.first->data);
                // Move to state 3 (postorder) for this node
                it.second = 3;
                // Push the updated state back onto the stack
                st.push(it); 

                // Push right child onto the stack for processing
                if (it.first->right != NULL) {
                    st.push({it.first->right, 1});
                }
            }

            // this is part of post
            else {
                // Store the node's data in the postorder traversal
                post.push_back(it.first->data);
            }
        }

        // Returning the traversals
        vector<vector<int>> result;
        result.push_back(pre);
        result.push_back(in);
        result.push_back(post);
        return result;
    }
};
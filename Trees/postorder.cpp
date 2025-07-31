#include <bits/stdc++.h> 
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root){
            return ans;
        }
        stack<TreeNode*> st;
        stack<TreeNode*> postorder;

        st.push(root);

        while(!st.empty()){
            TreeNode* curr = st.top();
            st.pop();
            postorder.push(curr);

            if(curr->left){
                st.push(curr->left);
            }
            if(curr->right){
                st.push(curr->right);
            }
        }

        while(!postorder.empty()){
            TreeNode* ele = postorder.top();
            ans.push_back(ele->val);
            postorder.pop();
        }

        return ans;
    }
};
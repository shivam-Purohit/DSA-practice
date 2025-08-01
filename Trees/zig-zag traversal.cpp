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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root){
            return ans;
        }
        bool flip = true;


        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            stack<TreeNode*> inorder; 
            int size= st.size();
            vector<int> temp;
            for(int i=0; i < size; i++ ){
                TreeNode* node = st.top();
                st.pop();
                temp.push_back(node->val);

                if(flip){
                    if(node->left){
                        inorder.push(node->left);
                    }
                    if(node->right){
                        inorder.push(node->right);
                    }
                }
                else{
                    if(node->right){
                        inorder.push(node->right);
                    }
                    if(node->left){
                        inorder.push(node->left);
                    }
                }
            }
            st = inorder;
            flip = !flip;
            ans.push_back(temp);
        }
        return ans;
    }
};
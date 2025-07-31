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
    int getMax(TreeNode* node){
        if(!node){
            return 0;
        }
        
        return 1 + max(getMax(node->left), getMax(node->right));
    }
    int maxDepth(TreeNode* root) {
        return getMax(root);
    }
};
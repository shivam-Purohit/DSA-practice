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
    // returns < max_depth, diameter> at that node
    pair<int, int> max_de(TreeNode* root){
        if(!root){
            return make_pair(0, 0);
        }

        pair<int, int> left = max_de(root->left);
        pair<int, int> right = max_de(root->right);
        int diameter_left = left.second;
        int diameter_right = right.second;
        int curr_dia = left.first + right.first;
        int returnmax = max(curr_dia, max(diameter_left, diameter_right));

        return make_pair(1+max(left.first, right.first), returnmax);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return max_de(root).second;
    }
};
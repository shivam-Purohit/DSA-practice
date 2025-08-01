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
    pair<int, bool> haiKy(TreeNode* root){
        if(!root){
            return make_pair(0, true);
        }

        pair<int, bool> left = haiKy(root->left);
        pair<int, bool> right = haiKy(root->right);

        if(left.second == false or right.second == false or (abs(right.first - left.first) > 1)){
            return make_pair(1 + max(left.first, right.first), false);
        }
       return make_pair(1+ max(left.first, right.first), true);
    }
    bool isBalanced(TreeNode* root) {
        return haiKy(root).second;
    }
};
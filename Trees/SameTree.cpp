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
    bool isSame(TreeNode* first, TreeNode* second){
        if(first and !second){
            return false;
        }
        if(!first and second){
            return false;
        }
        if(!first and !second){
            return true;
        }
        if(first->val == second->val){
            return ( isSame(first->left, second->left) and isSame(first->right, second->right) );
        }
        return false;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return isSame(p, q);
    }
};
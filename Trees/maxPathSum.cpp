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
    // pair (sum, max_sum);
    pair<int, int> max_de(TreeNode* root){
        if(!root){
            return make_pair(0,INT_MIN);
        }

        pair<int, int> left = max_de(root->left);
        pair<int, int> right = max_de(root->right);

        int include_one = root->val + max(0, max(left.first, right.first));
        int include_both = root->val + max(0, left.first) + max(0, right.first);
        
        int curr_max = max(max(max(include_both, max(left.second, right.second)), root->val), include_one);

        return make_pair(include_one, curr_max);

    }
    int maxPathSum(TreeNode* root) {
        return max_de(root).second;
    }
};
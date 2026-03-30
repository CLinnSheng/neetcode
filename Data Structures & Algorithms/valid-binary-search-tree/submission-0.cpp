/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*
 * Goal: Determine if the tree is a valid BST or not
 * Intuition: Traverse through every node and check at every node
 * IMPORTANT: It must be consistent throughout the tree (BST property)
 * Time Complexity: O(n)
 * Space Complexity: O(lgn)
*/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
      std::ios_base::sync_with_stdio(false);
      std::cin.tie(nullptr);
      std::cout.tie(nullptr);
    
      if (!root) return true;

      std::function<bool(TreeNode*, int, int)> dfs = [&](TreeNode* node, int left, int right) {
        
        if (!node) return true;
        if (!(node->val > left && node->val < right)) return false;

        return dfs(node->left, left, node->val) && dfs(node->right, node->val, right);
      };

      return dfs(root, INT_MIN, INT_MAX);
    }
};
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
Goal: Check whether is it a valid bst.
Intuition:
We need to check at every node and also make sure the whole subtree is valid as well
in order to achieve this we need to pass down the left and right boundary value while traversing down
    10
   /  \
  5    15
      /  \
    6     20
*/
class Solution {
private:
    bool helper(TreeNode* node, int left, int right)
    {
        if (node == nullptr)
            return true;

        if (!(node->val > left && node->val < right))
            return false;

        return helper(node->left, left, node->val) && helper(node->right, node->val, right);
    }
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, INT_MIN, INT_MAX);
    }
};

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
 * Check it recursively make sure every node in the tree obey the BST property
 * and we need to pass its maximum and minimum for each subtree
 * For instance the left subtree, we need to pass its maximum down, to amke sure we dont exceed
 * */
class Solution
{
  private:
    bool checkTree(TreeNode *node, int left, int right)
    {
        if (node == nullptr)
        {
            return true;
        }

        // Check whether is it valid or
        if (node->val > left && node->val < right)
        {
            return checkTree(node->left, left, node->val) && checkTree(node->right, node->val, right);
        }

        return false;
    }

  public:
    bool isValidBST(TreeNode *root)
    {
        return checkTree(root->left, INT_MIN, root->val) && checkTree(root->right, root->val, INT_MAX);
    }
};

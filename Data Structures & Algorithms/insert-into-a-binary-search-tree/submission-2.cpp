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
 * Insert a new node into binary saerch tree
 * Ok so everytime we inserting a new node, it must always obey the BST property
 * So there are 2 way is either insert at the leaf or insert within the current tree
 *
 * So the first problem is hwo can find the position?
 *
 * */
class Solution
{
  public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        // Base Case
        if (root == nullptr)
        {
            // Insert the new node
            return new TreeNode(val);
        }

        // Choose which path based on BST property
        if (root->val > val)
        {
            root->left = insertIntoBST(root->left, val);
        }
        else
        {
            root->right = insertIntoBST(root->right, val);
        }

        return root;
    }
};

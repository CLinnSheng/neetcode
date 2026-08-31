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
 * Find the number of good nodes within the tree
 * Good node: If the path from the root of the tree to the node x contains no nodes with a value greater than the value
 * of node x We can do it in a recursive pattern and pass information about the largest node down so far
 * */
class Solution
{
  public:
    int goodNodes(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        return 1 + recursive(root->left, root->val) + recursive(root->right, root->val);
    }

    int recursive(TreeNode *node, int currMax)
    {
        if (node == nullptr)
        {
            return 0;
        }

        int cnt{};
        if (node->val >= currMax)
        {
            cnt++;
        }

        return cnt + recursive(node->left, std::max(currMax, node->val)) +
               recursive(node->right, std::max(currMax, node->val));
    }
};

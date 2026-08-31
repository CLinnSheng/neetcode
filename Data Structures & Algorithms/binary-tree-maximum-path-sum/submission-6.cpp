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
 * Finding the max Path sum of any non-empty path
 * Take note that the node val can be in negative so is not ideal to include all
 * And is not necessarily to start from the root
 * So theres is a few way.
 * First including the root which is left + root + right
 * Seoncd is just 1 subtree left only or right only
 * Third is dont include any subtree at all. This handles when all node in the tree is negative so we choose the min
 * node in the tree
 * Can compute the sum in a post order traversal manner
 * */
#include <algorithm>
#include <climits>
class Solution
{
  public:
    int maxPathSum(TreeNode *root)
    {
        int maxSum{INT_MIN};
        dfs(root, maxSum);

        return maxSum;
    }

    int dfs(TreeNode *node, int &maxSum)
    {
        if (node == nullptr)
        {
            return 0;
        }

        // Traverse both subtree
        // Clamp to 0 so we can either include it or not
        int left = std::max(0, dfs(node->left, maxSum));
        int right = std::max(0, dfs(node->right, maxSum));

        // Cases where we inlcude the curr node as the connecting node
        int pathSum = node->val + left + right;
        maxSum = std::max(pathSum, maxSum);

        // Only choose the path that we want
        return node->val + std::max(left, right);
    }
};

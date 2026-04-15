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

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        // First we need to find the first node where it equal to the head of the subroot
        // Then recursively check down the tree
        // Base Case
        if (root == nullptr)
        {
            return false;
        }

        // Reach the end
        if (subRoot == nullptr)
        {
            return true;
        }

        if (root->val == subRoot->val && isSameTree(root, subRoot))
        {
            return true;
        }

        // Finding the same head node
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool isSameTree(TreeNode* root, TreeNode* subRoot)
    {
        if (root == nullptr || subRoot == nullptr)
        {
            return root == subRoot;
        }

        return root->val == subRoot->val && isSameTree(root->left, subRoot->left) && isSameTree(root->right, subRoot->right);
    }
};

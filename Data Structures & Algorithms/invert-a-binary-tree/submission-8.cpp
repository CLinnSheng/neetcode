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
    TreeNode* invertTree(TreeNode* root) {
        // Base Case
        if (root == nullptr)
        {
            return nullptr;
        }
        // Swap
        std::swap(root->left, root->right);
        // Invert both cihld node
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};

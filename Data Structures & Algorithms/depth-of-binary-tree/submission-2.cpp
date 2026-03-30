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
Intuition: Can use dfs
*/
class Solution {
private:
    int dfs(TreeNode* node)
    {
        if (node == nullptr)
            return 0;

        return 1 + std::max(dfs(node->left), dfs(node->right));
    }
public:
    int maxDepth(TreeNode* root) {
        return dfs(root);
    }

};

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
Intuition:
Check at every level
*/
class Solution {
private:
    std::pair<bool, int> helper(TreeNode* node)
    {
        if (node == nullptr)
            return {true, 0};

        auto left = helper(node->left);
        auto right = helper(node->right);

        return {left.first && right.first && (std::abs(left.second - right.second) <= 1), 1 + std::max(left.second, right.second)};
    }
public:
    bool isBalanced(TreeNode* root) {
        return helper(root).first;
    }
};

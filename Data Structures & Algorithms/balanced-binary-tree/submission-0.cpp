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
Intuition: Check every node whether is it balanced by comparing it left subtree and rightsubtree
Time Complexity: O(nlgn) because we checking the height on every single node
Space Complexity: O(lgn) because of the recursive call stack
*/
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return helper(root).first;
    }

    std::pair<bool, int> helper(TreeNode* root)
    {
        if (root == nullptr) return {true, 0};

        auto left = helper(root->left);
        auto right = helper(root->right);

        return {left.first && right.first && std::abs(right.second - left.second) <= 1,
                1 + std::max(left.second, right.second)};
    }
};

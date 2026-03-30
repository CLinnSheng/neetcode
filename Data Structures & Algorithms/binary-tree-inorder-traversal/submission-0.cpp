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
    void helper(std::vector<int>& answer, TreeNode* node)
    {
        if (!node)
            return;

        helper(answer, node->left);
        answer.emplace_back(node->val);
        helper(answer, node->right);
    }
    
public:
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> answer;

        helper(answer, root);

        return answer;
    }
};
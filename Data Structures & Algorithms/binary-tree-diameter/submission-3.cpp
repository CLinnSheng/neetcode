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
Can use dfs treat every node as the root node then compute the diameter by taking the sum of left and right.
And whenever moving up we chose the longer 1
*/
class Solution {
private:
    int dfs(TreeNode* node, int& answer)
    {
        if (node == nullptr)
            return 0;

        int left = dfs(node->left, answer);
        int right = dfs(node->right, answer);

        answer = std::max(answer, left + right);

        return 1 + std::max(left, right);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) 
    {
        int answer{};
        dfs(root, answer);
        return answer;
    }
};

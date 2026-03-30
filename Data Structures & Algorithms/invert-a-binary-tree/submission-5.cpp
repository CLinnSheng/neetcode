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
The first appraoch will be using recursive which will be invert it row by row.
Which is BFS.
We can also use queue to implement BFS
*/
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // Approach 1: Recursive
        // if (!root)
        //     return nullptr;

        // std::swap(root->left, root->right);
        // invertTree(root->left);
        // invertTree(root->right);

        // return root;

        // Approach 2: BFS
        std::deque<TreeNode*> queue;
        TreeNode* temp{root};
        queue.emplace_back(temp);

        while (!queue.empty())
        {
            auto top{queue.back()};
            queue.pop_back();

            if (top == nullptr)
                continue;
            std::swap(top->left, top->right);
            queue.emplace_back(top->left);
            queue.emplace_back(top->right);
        }

        return root;
    }
};

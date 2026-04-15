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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Check whether the tree is the same or not
        // Things to make sure is they are checking at the same level and same node
        // Need to handle when one of them is nullptr
        if (p == nullptr || q == nullptr)
        {
            return p == q;
        }

        // Over here we already confirm that both p & q are not nullptr
        // Then recursion check on each substree
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

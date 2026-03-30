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
Goal: Find the lowest common ancestor of the 2 nodes given
Lowest common ancestor between p and q is the lowest node in a tree T such that both p & q are descendants.
Ancestor is allowed to be a descendent of itself

Intuition:
The tree give is a BST. That means we can make us of it property such that the right node is larger and the small node is smaller
So we must dfs down the tree until we find the correct subtree
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        while (true)
        {
            if (root->val > p->val && root->val > q->val)
                root = root->left;
            else if (root->val < p->val && root->val < q->val)
                root = root->right;
            else
                return root;
        }
        return nullptr;    
    }
};

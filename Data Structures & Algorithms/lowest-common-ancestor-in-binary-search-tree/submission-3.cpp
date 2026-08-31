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
 * The tree is a BST. Find the lowest common ancestor between 2 nodes p & q.
 * One importnat thing --> Ancestor is allowed to be a descendent of itself
 * IMPORTANT HINT: Tree given is a BST
 * So we can make use of its property
 * */
class Solution
{
  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // Base Case
        if (root == nullptr)
        {
            return root;
        }

        // BST Property
        if (p->val > root->val && q->val > root->val)
        {
            // On the right subtree
            return lowestCommonAncestor(root->right, p, q);
        }
        else if (p->val < root->val && q->val < root->val)
        {
            // On the left subtree
            return lowestCommonAncestor(root->left, p, q);
        }

        return root;
    }
};

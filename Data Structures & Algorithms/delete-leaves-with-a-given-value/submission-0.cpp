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
Goal: Delete all the leaf nodes with value 'target'.
NOTE: If delete a leaf node with value target, if its parent node becomes a leaf node and has the
value target. Then it should be deleted as well

Intuition:
Think of which traversal best to solve it
One important key observation from the problem statemnt is if the parent node become a leaf node we need to delete it as well
This give a hint of using postorder traversal.
Becaue we dfs through the deep and do the processing at the very end. So when we return from the leaf node to the parent node.
The leaf node already been deleted
*/
class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target)
    {
        if (root == nullptr)
            return nullptr;

        // PostOrder Traversal
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);

        // Processing Step: Check whether is it a leaf or not 
        // and has the value target
        if (root->left == nullptr && root->right == nullptr && root->val == target)
            return nullptr;

        return root;    
    }
};
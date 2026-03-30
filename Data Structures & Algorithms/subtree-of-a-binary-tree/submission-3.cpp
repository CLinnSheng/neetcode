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
Check recursively at each level when have equal value only traverse down
Key important things is if subroot is empty then it is def a subtree in the root
Time Complexity: O(n * m) going through every node in both root and subroot
*/
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr)
            return false;
        if (subRoot == nullptr)
            return true;

        // Only travese down to check if it has similar node's value
        if(root->val == subRoot->val && helper(root, subRoot))
            return true;

        // Else check the root's children
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool helper(TreeNode* root, TreeNode* subRoot)
    {

        if (subRoot == nullptr || root == nullptr)
            return subRoot == root;

        return root->val == subRoot->val && helper(root->left, subRoot->left) && helper(root->right, subRoot->right);
    }
};

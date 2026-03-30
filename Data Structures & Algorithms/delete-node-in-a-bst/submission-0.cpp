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
 Make use of the BST property, keep searching until we find the key
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        // DFS / Recursive search with the BST property
        if (root == nullptr)
            return nullptr;

        if (root->val > key)
            root->left = deleteNode(root->left, key);
        else if (root->val < key)
            root->right = deleteNode(root->right, key);
        else
        {
            // Found the node to be deleted.
            // If one of the child is empty then retur not the empty 1.
            // if both are not empty, then we need to select from the right subtree.
            // because of the BST property, then after that chooses the most left element of the subtree
            // because it gonna be the smallest element
            if (root->left == nullptr)  return root->right;
            if (root->right == nullptr) return root->left;

            TreeNode* temp{root->right};

            while (temp->left)
                temp = temp->left;

            // Append the left to the smallest one because the one from the left subtree is even smaller
            temp->left = root->left;
            TreeNode* res{root->right};
            delete root;
            return res;
        }
        return root;
    }
};
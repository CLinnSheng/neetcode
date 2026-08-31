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
 * Tree is BST, so make use of its property
 * First thing first find the node then we delete the node.
 * 3 condition when removing the node.
 * 1. The nodes have no leaf at all
 * 2. The node have only 1 leaf
 * 3. The node have 2 leaves
 * */
class Solution
{
  public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == nullptr)
        {
            return root;
        }

        if (root->val == key)
        {
            if (root->left == nullptr && root->right == nullptr)
            {
                return nullptr;
            }
            else if (root->left && root->right == nullptr)
            {
                return root->left;
            }
            else
            {
                // Only need to handle when right subtree is not empty
                // Need to find the correct node to replace
                auto temp = root->right;
                while (temp->left != nullptr)
                {
                    temp = temp->left;
                }

                // Replace it
                root->val = temp->val;

                // Delete the successor node
                root->right = deleteNode(root->right, temp->val);
            }
        }
        else if (root->val > key)
        {
            root->left = deleteNode(root->left, key);
        }
        else
        {
            root->right = deleteNode(root->right, key);
        }

        return root;
    }
};

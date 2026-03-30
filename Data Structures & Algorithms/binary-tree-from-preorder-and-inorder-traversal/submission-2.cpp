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
Build a tree from a preorder and inorder traversal array

Intuition:
How can we make use of the properties of preorder and inorder to build a tree
Preorder: top -> left -> right
The first node is always the root node

Inorder: left -> top -> right
The node on its side is actually its child node
all the elements on its left belong to the left subtree and the right belongs to the right subtree
So we can easily find the child of the root node by simply taking the left and right in its inorder array
So we need a hashmap that store the index with its value

*/
class Solution {
private:
    int preIndex{};
    std::unordered_map<int, int> indices;

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        for (int i{}; i < inorder.size(); i++)
            indices[inorder[i]] = i;

        std::function<TreeNode*(int, int)> helper = [&](int left, int right) -> TreeNode*
        {
            // Base case
            if (left > right)
                return nullptr;

            TreeNode* root = new TreeNode(preorder[preIndex++]);
            int middleIndex = indices[root->val];

            root->left = helper(left, middleIndex - 1);
            root->right = helper(middleIndex + 1, right);

            return root;
        };

        return helper(0, inorder.size() - 1);
    }
};

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
 * Build tree from a preorder and inorder arrays
 * Preorder: Always push the root node first, so every node in the preorder array will just simply be the root node
 * arr.push(root)
 * preorder(root->left)
 * preorder(root->right)
 *
 * Inorder: Its left and right subtree will just be on the left and right of the root node
 * preorder(root->left)
 * arr.push(root)
 * preorder(root->right)
 *
 * Ok what we can do is first get the root node from preorder traversal and then we need to find out the exact same node
 * in the inorder traversal so we can extract i - i + i + 1
 * */

#include <unordered_map>
#include <vector>
class Solution
{
  public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        std::unordered_map<int, int> inorder_map;
        for (int i{}; i < inorder.size(); i++)
        {
            inorder_map[inorder[i]] = i;
        }

        int preOrderIndex{};
        return dfs(preorder, inorder, inorder_map, preOrderIndex, 0, inorder.size() - 1);
    }

    TreeNode *dfs(const std::vector<int> &preorder, const std::vector<int> &inorder,
                  const std::unordered_map<int, int> &map, int &preOrderIndex, int left, int right)
    {
        // Base case
        if (left > right)
        {
            return nullptr;
        }

        int rootVal = preorder[preOrderIndex++];
        TreeNode *root = new TreeNode(rootVal);

        int mid = map.at(rootVal);

        root->left = dfs(preorder, inorder, map, preOrderIndex, left, mid - 1);
        root->right = dfs(preorder, inorder, map, preOrderIndex, mid + 1, right);

        return root;
    }
};

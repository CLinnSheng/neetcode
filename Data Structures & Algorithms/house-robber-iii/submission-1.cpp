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
Automatically contact the police if 2 directly-linked houses were broken
Goal: Return the maximum amount of money the theif can rob without alerting the police

Intuition:
So at every point we actually have only 2 choices which is either choose the root node or choose both the child node
So this become a selection problem which is by using recursive
This will lead to O(2^n)

Can we further optimize it by using caching?
yes we can if we observe from the brute force solution, some of the nodes actually visited more than once.
If we have information that store on the specific node the maximum point it can achieve then
we can optimize it to O(n)
*/
class Solution {
    std::unordered_map<TreeNode*, int> cache;
public:
    int rob(TreeNode* root) 
    {
        // Brute force
        // if (root == nullptr)
        //     return 0;

        // // If we choose the current node
        // int answer = root->val;
        // if (root->left)
        //     answer += rob(root->left->left) + rob(root->left->right);
        // if (root->right)
        //     answer += rob(root->right->left) + rob(root->right->right);

        // return std::max(answer, rob(root->left) + rob(root->right));

        if (root == nullptr)
            return 0;

        // Check whether we visited this node before or not
        if (cache.find(root) != cache.end())
            return cache[root];

        int answer = root->val;
        if (root->left)
            answer += rob(root->left->left) + rob(root->left->right);
        if (root->right)
            answer += rob(root->right->left) + rob(root->right->right);

        return cache[root] = std::max(answer, rob(root->left) + rob(root->right));
    }
};
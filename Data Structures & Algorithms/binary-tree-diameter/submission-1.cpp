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
Goal: Find the longest path between any two nodes in the tree
Intuition: The distance between 2 nodes that go through the root node will be the largest rather than straight from root to the leave
So we will dfs each root node from the left and right and sum it up

Time Complexity; O(n)
Space Complexity: O(lgN)
*/
#include <ios>
#include <iostream>
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) 
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        
        int ans = 0;

        dfs(root, ans);

        return ans;
    }
    
    int dfs(TreeNode* root, int& ans)
    {
        if (root == nullptr) return 0;
        
        int left = dfs(root->left, ans);
        int right = dfs(root->right, ans);
        
        ans = std::max(ans, left + right);

        return 1 + std::max(left, right);
    }
};
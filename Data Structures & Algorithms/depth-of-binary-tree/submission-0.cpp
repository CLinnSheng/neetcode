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
Time Complexity: O(n)
Space Complexity: O(lgN) because of recursive call building a stack of pointer point to the last function call
*/
#include <algorithm>
class Solution {
public:
    int maxDepth(TreeNode* root) 
    {
        if (root == nullptr) return 0;
        
        return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
    }
};
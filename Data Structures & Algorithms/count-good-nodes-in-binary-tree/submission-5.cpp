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
Goal: Return the number of good nodes in the tree
Good Node: Path from the root of the tree to node x contains no nodes with a value greater than value of node x.

Intuition:
Use dfs or recursive and passing the current maximum value so that we know that the current traversed node is good node or not
Time Complexity: O(n)
*/
class Solution {
private:
    int answer{};

    void helper(TreeNode* node, int maximumVal)
    {
        if (node == nullptr)
            return;
        
        // Determine whether is good node or not
        if (node->val >= maximumVal)
        {
            answer++;
            maximumVal = node->val;

        }

        helper(node->left, maximumVal);
        helper(node->right, maximumVal);
    }
    
public:
    int goodNodes(TreeNode* root) 
    {
        // Take note the root node itself is always a good node
        // And val can be negative sa well
        helper(root, root->val);
        return answer;    
    }
};

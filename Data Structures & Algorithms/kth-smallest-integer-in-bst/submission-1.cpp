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
Goal: Return the kth smallest value

Intuition:
Brute force way will be push everything into the heap. But we can achieve better time complexity
by using of the BST property. So we need to inorder traversal
*/
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) 
    {
        std::deque<TreeNode*> stack;
        TreeNode* temp{root};

        while (temp || !stack.empty())
        {
            // Go all the way left
            while (temp)
            {
                stack.emplace_back(temp);
                temp = temp->left;
            }

            // Pop from the top of the stack which is the current smallest value
            temp = stack.back();
            stack.pop_back();
            k--;

            if (k == 0)
                return temp->val;

            temp = temp->right; 
        }
        return -1;
    }
};

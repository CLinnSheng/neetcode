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
class Solution {
// Approach 1 : Recursive
// private:
//     void helper(std::vector<int>& answer, TreeNode* node)
//     {
//         if (!node)
//             return;
        
//         answer.emplace_back(node->val);
//         helper(answer, node->left);
//         helper(answer, node->right);
//     }
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         std::vector<int> answer;
//         helper(answer, root);
//         return answer;
//     }

    public:
        vector<int> preorderTraversal(TreeNode* root)
        {
            // Approach 2: Using stack, same implementation as recursive
            std::deque<TreeNode*> stack;
            TreeNode* temp{root};
            std::vector<int> answer;

            while (temp || !stack.empty())
            {
                if (temp)
                {
                    answer.emplace_back(temp->val);
                    stack.emplace_back(temp);
                    temp = temp->left;
                }
                else
                {
                    temp = stack.back();
                    stack.pop_back();
                    temp = temp->right;
                }
            }
            return answer;
        }
};
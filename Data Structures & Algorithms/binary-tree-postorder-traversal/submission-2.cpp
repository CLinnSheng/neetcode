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
// Approach 1: Recursive
// private:
//     void helper(std::vector<int>& answer, TreeNode* node)
//     {
//         if (!node)
//             return;
        
//         helper(answer, node->left);
//         helper(answer, node->right);
//         answer.emplace_back(node->val);
//     }
// public:
//     vector<int> postorderTraversal(TreeNode* root) {
//         std::vector<int> answer;
//         helper(answer, root);
//         return answer;
//     }

    public:
        vector<int> postorderTraversal(TreeNode* root)
        {
            // Approach 2: Using stack same implementation as recursive
            std::vector<int> answer;
            std::deque<TreeNode*> stack;
            TreeNode* temp{root};

            while (temp || !stack.empty())
            {
                if (temp)
                {
                    stack.emplace_back(temp);
                    answer.emplace_back(temp->val);
                    temp = temp->right;
                }
                else
                {
                    temp = stack.back();
                    stack.pop_back();
                    temp = temp->left;
                }
            }
            std::reverse(answer.begin(), answer.end());
            return answer;
        }
};
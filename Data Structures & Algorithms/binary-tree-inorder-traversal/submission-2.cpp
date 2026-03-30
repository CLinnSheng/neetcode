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
//     void helper(std::vector<int>& answer, TreeNode* node)
//     {
//         if (!node)
//             return;

//         helper(answer, node->left);
//         answer.emplace_back(node->val);
//         helper(answer, node->right);
//     }

// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         std::vector<int> answer;

//         helper(answer, root);

//         return answer;
//     }

    public:
        vector<int> inorderTraversal(TreeNode* root)
        {
            std::deque<TreeNode*> stack;
            // Keep going to the left first
            // if null then start to push into the answer array, then going back to prev node
            // and check whether got right node or not, if have continue again
            std::vector<int> answer;
            TreeNode* temp{root};

            while (temp || !stack.empty())
            {
                while (temp)
                {
                    stack.emplace_back(temp);
                    temp = temp->left;
                }

                temp = stack.back();
                answer.emplace_back(temp->val);
                stack.pop_back();

                // Traverse into the right
                // Almost same implementation with recursive if you observe properly
                temp = temp->right;
            }
            return answer;
        }
};
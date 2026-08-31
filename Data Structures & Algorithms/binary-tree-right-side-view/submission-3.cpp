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
#include <deque>
#include <vector>
using std::vector;
/*
 * Getting the binary tree right side view. We can use level order traversal and only push it to the answer when we at
 * the last element for that level
 * */
class Solution
{
  public:
    vector<int> rightSideView(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }

        vector<int> ans;
        std::deque<TreeNode *> queue;
        queue.push_back(root);

        while (!queue.empty())
        {
            int level_size = queue.size();

            while (true)
            {
                auto currNode = queue.front();
                queue.pop_front();

                if (currNode->left)
                {
                    queue.push_back(currNode->left);
                }
                if (currNode->right)
                {
                    queue.push_back(currNode->right);
                }

                level_size--;
                if (level_size == 0)
                {
                    ans.push_back(currNode->val);
                    break;
                }
            }
        }

        return ans;
    }
};

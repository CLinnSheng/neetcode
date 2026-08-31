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
/*
 * Traverse the tree in level order traversal
 * we can use bfs method because bfs allow every node in the same level spread at the same time
 * We can store the nodes in a queue because the order of the nodes matter
 * */
using std::vector;
class Solution
{
  public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        // Base Case
        if (!root)
        {
            return {};
        }

        vector<vector<int>> ans;
        std::deque<TreeNode *> queue;
        queue.push_back(root);

        while (!queue.empty())
        {
            int n = queue.size();
            vector<int> level;

            while (n)
            {
                auto currNode = queue.front();
                queue.pop_front();

                level.push_back(currNode->val);

                if (currNode->left)
                {
                    queue.push_back(currNode->left);
                }
                if (currNode->right)
                {
                    queue.push_back(currNode->right);
                }

                n--;
            }

            ans.push_back(level);
        }

        return ans;
    }
};

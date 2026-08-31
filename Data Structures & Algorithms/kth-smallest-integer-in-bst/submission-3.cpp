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
 * Finding the Kth Smallest Integer in BST.
 * So what we can do is finding the smallest node first then walk backwards from that and remember to push all the nodes
 * we visited
 * */
class Solution
{
  public:
    int kthSmallest(TreeNode *root, int k)
    {
        std::deque<TreeNode *> queue;
        TreeNode *node = root;

        while (node)
        {
            queue.push_back(node);
            node = node->left;
        }

        while (!queue.empty())
        {
            auto currNode = queue.back();
            queue.pop_back();
            k--;

            if (k == 0)
            {
                return currNode->val;
            }

            // Visit its right subtree and push it into the queue if have
            // Because everything in the currnode subtree either left or right will always smaller than its root
            if (currNode->right)
            {
                currNode = currNode->right;

                while (currNode)
                {
                    queue.push_back(currNode);
                    currNode = currNode->left;
                }
            }
        }

        return -1;
    }
};

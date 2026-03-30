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
Goal: Return only the values of the nodes that are visible from the right side.

Intuition:
The answer array must in the order from top to bottom.
So that means we need to use level order traversal.
We can do level order traversal, then just get the last element at each level which is also
equivalent to the most right side nodes.
Time Complexity: O(n)
*/
class Solution {
public:
    vector<int> rightSideView(TreeNode* root)
    { 
        if (root == nullptr)
            return {};

        std::deque<TreeNode*> queue;
        std::vector<std::vector<TreeNode*>> levelNodes;
        std::vector<TreeNode*> temp;
        queue.emplace_back(root);

        while (!queue.empty())
        {
            temp.clear();
            int n(queue.size());

            while (n)
            {
                auto currNode{queue.front()};
                queue.pop_front();
                temp.emplace_back(currNode);

                if (currNode->left)
                    queue.emplace_back(currNode->left);
                if (currNode->right)
                    queue.emplace_back(currNode->right);

                n--;
            }
            levelNodes.emplace_back(temp);
        }

        std::vector<int> answer;
        for (const auto& levelNode : levelNodes)
            answer.emplace_back(levelNode.back()->val);

        return answer;
    }
};

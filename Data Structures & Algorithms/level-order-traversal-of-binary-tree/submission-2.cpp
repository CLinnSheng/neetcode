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
Goal: Traverse the tree in the level from left to right.
Intuition:
Since we traversing the tree level by level from left to right. We can make use of a queue
which has the property of FIFO
Time Complexity: O(n)
*/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        if (root == nullptr)
            return {};
            
        std::vector<std::vector<int>> answer;
        std::deque<TreeNode*> queue;
        queue.emplace_back(root);
        std::vector<int> temp;

        while (!queue.empty())
        {
            int n(queue.size());
            temp.clear();
            
            while (n)
            {
                auto currNode{queue.front()};
                queue.pop_front();
                temp.emplace_back(currNode->val);

                if (currNode->left)
                    queue.emplace_back(currNode->left);
                if (currNode->right)
                    queue.emplace_back(currNode->right);

                n--;
            }
            answer.emplace_back(temp);
        }
        return answer;    
    }
};

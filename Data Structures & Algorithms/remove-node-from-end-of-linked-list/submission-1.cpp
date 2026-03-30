/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/*
Goal: Remove nth node from the end of the list and return the beginning of the list

Intuition:
We need information for the node before and after the node being deleted.
So the easiest way is actually store the list of nodes in an array then we can easily access
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        std::vector<ListNode*> nodes;
        ListNode* temp{head};
        while (temp)
        {
            nodes.emplace_back(temp);
            temp = temp->next;
        }    

        if (nodes.size() == 1 && n == 1)
            return nullptr;

        int size(nodes.size());
        int index(size - n);

        // Handle first node
        if (index == 0)
        {
            return nodes[1];
        }
        else if (index == size - 1)
        {
            auto &node{nodes[index - 1]};
            node->next = nullptr;
        }
        else
        {
            auto &before{nodes[index - 1]};
            auto &after{nodes[index + 1]};
            before->next= after;
        }
        return head;
    }
};

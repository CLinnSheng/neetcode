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

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        // Just iterate through the list
        // easiest way is stored in side an array
        // then just reconnect for the removed nodes

        ListNode* temp = head;
        std::vector<ListNode*> nodes;

        while (temp)
        {
            nodes.push_back(temp);
            temp = temp->next;
        }

        int size = nodes.size();
        int index = size - n;

        if (size == 1 && index == 0) 
        {
            return nullptr;
        }

        // First Node
        if (index == 0)
        {
            return nodes[1];
        }
        // Last Node
        else if (index == size - 1)
        {
            nodes[index - 1]->next = nullptr;
        }
        else
        {
            nodes[index - 1]->next = nodes[index + 1];
        }

        return head;
    }
};

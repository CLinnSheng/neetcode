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
Goal: Reorder the list to [0, n-1, 1, n-2, 2, ...]

Intuition:
If you notice the order is in a specific sequence.
The most straight away is actually using an array to store the nodes and use 2 pointers to keep track which node to place next
Time Complexity: O(n)
Space Complexity: O(n)
*/
class Solution {
public:
    void reorderList(ListNode* head) 
    {
        std::vector<ListNode*> order;
        ListNode* temp{head};
        while (temp)
        {
            order.emplace_back(temp);
            temp = temp->next;
        }

        int left{}, right(order.size() - 1);
        std::vector<ListNode*> reverse_order;
        while (left <= right)
        {
            // Condition when reach end of the list
            if (left == right)
            {
                reverse_order.emplace_back(order[left]);
                break;
            }

            reverse_order.emplace_back(order[left++]);
            reverse_order.emplace_back(order[right--]);
        }

        head->next = nullptr;
        for (int index{1}; index < reverse_order.size(); index++)
        {
            head->next = reverse_order[index];
            head = head->next;
        }
        head->next = nullptr; // Because the original order node might linked to any other node
    }
};

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
A bit similar to reverse linked list
But this 1 with a little bit of constraint which is just reverse within the range [left, right]

Intuition:
We only need to reverse within the range [left, right]
So information of the nodes before and after the range we need
*/
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* prevLeft{dummy};

        // Find the node before the left boundary
        for (int i{}; i < left - 1; i++)
            prevLeft = prevLeft->next;

        ListNode* node{prevLeft->next};
        // Reverse the node within the range
        ListNode* prev{};
        for (int i{}; i < right - left + 1; i++)
        {
            ListNode* temp{node->next};
            node->next = prev;
            prev = node;
            node = temp;
        }

        // Relink for the left and right node outside the boundary
        prevLeft->next->next = node;
        prevLeft->next = prev;

        return dummy->next;
    }
};
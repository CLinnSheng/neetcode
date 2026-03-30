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

/**
 * Goal: Remove the nth node from the end of the linked list.
 * 
 * Approach:
 * 1. Find the total length of the linked list.
 * 2. Calculate the number of traversals needed to reach the node before the target node.
 * 3. Handle the special case where the node to delete is the first one.
 *
 * Time Complexity: O(n) – We traverse the linked list once.
 * Space Complexity: O(1) – No extra space beyond a few variables.
 */
#include <ios>
#include <iostream>

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        // Early exit if no node needs to be removed
        if (!head || n == 0) return head;

        // Step 1: Compute the length of the linked list
        int length = 0;
        ListNode* temp = head;
        while (temp) {
            ++length;
            temp = temp->next;
        }

        // Step 2: Calculate the position of the node before the target node
        int targetPos = length - n - 1;

        // Handle the case where the first node is to be deleted
        if (targetPos == -1) {
            ListNode* toDelete = head;
            head = head->next;
            delete toDelete;
            return head;
        }

        // Step 3: Traverse to the node just before the one to be deleted
        temp = head;
        for (int i = 0; i < targetPos; ++i) {
            temp = temp->next;
        }

        // Remove the nth node
        ListNode* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;

        return head;
    }
};

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
Have 2 pointer 1 pointed at the curr 1 and another pointed at the prev 1
Time Complexity: O(n)
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev{};

        while (head != nullptr)
        {
            ListNode* temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }

        return prev;
    }
};

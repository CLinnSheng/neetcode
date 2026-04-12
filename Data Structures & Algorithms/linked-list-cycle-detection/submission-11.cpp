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
    bool hasCycle(ListNode* head) {
        // Check whether we have cycle or not
        // The simplest way is having 2 pointer and 1 is much more faster
        // So when either one of it is nullptr, then that's mean definitely no cycle in the LL

        // Base Case
        if (head == nullptr)
        {
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
         
            if (slow == fast)
            {
                return true;
            }

        }

        return false;
    }
};

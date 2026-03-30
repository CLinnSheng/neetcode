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
Goal: Check whether got cycle or not.

Intuition:
The easiest way is actually having a hash set that store the list of node
Time Complexity: O(n)
Space Complexity: O(n)

Can further optmize it so that the space complexity is O(1)?
We can use fast ptr and slow ptr approach where fast ptr moving 2 nodes at once and slow ptr moving one node at once
So if they two land on the same node means there is cycle
*/
class Solution {
public:
    bool hasCycle(ListNode* head) {
        // Time Complexity: O(n)
        // Space Complexity: O(1)
        // std::unordered_set<ListNode*> set;
        // while (head)
        // {
        //     if (set.count(head))
        //         return true;

        //     set.insert(head);
        //     head = head->next;
        // }
        // return false;
        

        // Approach 2
        // Space Complexity: O(1)

        ListNode* slow{head};
        ListNode* fast{head};
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow)
                return true;
        }
        return false;
    }
};

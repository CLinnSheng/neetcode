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
*/
class Solution {
public:
    bool hasCycle(ListNode* head) {
        std::unordered_set<ListNode*> set;

        while (head)
        {
            if (set.count(head))
                return true;

            set.insert(head);
            head = head->next;
        }

        return false;
    }
};

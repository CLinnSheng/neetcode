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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Just having 2 pointer at each LL, and iterate through

        // Base Case
        if (list1 == nullptr)
        {
            return list2;
        }
        if (list2 == nullptr)
        {
            return list1;
        }

        ListNode* head = new ListNode();
        ListNode* temp = head;

        while (list1 && list2)
        {
            if (list1->val > list2->val)
            {
                temp->next = list2;
                list2 = list2->next;
            }
            else
            {
                temp->next = list1;
                list1 = list1->next;
            }

            temp = temp->next;
        }

        // Check if any list didnt traversed fin
        if (list1)
        {
            temp->next = list1;
        }
        if (list2)
        {
            temp->next = list2;
        }

        return head->next;
    }
};

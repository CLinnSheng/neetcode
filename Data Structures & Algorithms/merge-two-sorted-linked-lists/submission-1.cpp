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
Intuition:
Have 2 pointer 1 on each linkedlist
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;

        ListNode* head = new ListNode();
        ListNode* temp = head;

        while (list1 != nullptr && list2 != nullptr)
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

        // In case one out of node already
        while (list1 != nullptr)
        {
            temp->next = list1;
            list1 = list1->next;
            temp = temp->next;
        }
        while (list2 != nullptr)
        {
            temp->next = list2;
            list2 = list2->next;
            temp = temp->next;
        }

        return head->next;
    }
};

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
 * Each LL is sorted. How can we merge all of it together into 1?
 * Merging n (where n > 2) is hard but we know that merging 2 linked list is easy
 * So we can actually just keep merging 2 linked list
 * Time Complexity: O(m*n)
 * - m -> Length of lists
 * - n -> Longest linked list
 *
 * Space Complexity: O(1)
 *
 * */

#include <vector>
class Solution
{
  private:
    ListNode *mergeLinkedList(ListNode *list1, ListNode *list2)
    {
        ListNode *head = new ListNode();
        ListNode *temp = head;

        while (list1 && list2)
        {
            if (list1->val > list2->val)
            {
                temp->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            else
            {
                temp->next = new ListNode(list1->val);
                list1 = list1->next;
            }

            temp = temp->next;
        }

        // Append the longer LL which never traversed finish
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

  public:
    ListNode *mergeKLists(std::vector<ListNode *> &lists)
    {
        int n = lists.size();

        // Base Case
        if (n == 0)
        {
            return nullptr;
        }

        // Keeping merging 2 linkedlist
        for (int i{1}; i < n; i++)
        {
            lists[0] = mergeLinkedList(lists[0], lists[i]);
        }

        return lists[0];
    }
};

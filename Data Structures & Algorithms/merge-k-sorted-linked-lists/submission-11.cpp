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
#include <vector>
class Solution
{
  public:
    ListNode *mergeKLists(std::vector<ListNode *> &lists)
    {
        // Merging K Sorted LL
        // Key observation is each LL is already sorted
        // So to easy things up we just merged 2 LL isntead of N LL at one time
        // Time Complexity: O(n*k)
        // int k = lists.size();

        // // Base Case
        // if (k == 0)
        // {
        //     return nullptr;
        // }

        // // So keep merging the merged LL with the new LL
        // for (int i{1}; i < k; i++)
        // {
        //     lists[0] = helper(lists[0], lists[i]);
        // }

        // return lists[0];

        // A more efficient approach is actually divide & conquer
        // This can reduce it to O(nlgk)
        return divide(lists, 0, lists.size() - 1);
    }

    ListNode *divide(const std::vector<ListNode*>& lists, int left, int right)
    {
        // BaseCase
        if (left > right)
        {
            return nullptr;
        }
        if (left == right)
        {
            return lists[left];
        }

        // Further Dividing
        int middle = left + (right - left) / 2;
        ListNode* leftSide = divide(lists, left, middle);
        ListNode* rightSide = divide(lists, middle + 1, right);

        return conquer(leftSide, rightSide);
    }

    ListNode *conquer(ListNode* list1, ListNode* list2)
    {
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

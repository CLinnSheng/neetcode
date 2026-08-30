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
 * Instead of merging so many linked list in one time, why not we merge 2 linked list at one time? is much more easier
 * Merging Time Complextiy: O(N) where N is the longest linked list
 * Looping: O(K)
 * Time Complexity: O(N * K)
 *
 * How can we further optimze it?
 * We can actually use divide and conquer method
 * This will reduce to O(N*lg(K))
 * Why divide and conquere works, because is each subproblem is doing the same thing so we can just merge their results
 * A little bit similar to divide and conquer sort
 * */
class Solution
{
  private:
    ListNode *merge(ListNode *list1, ListNode *list2)
    {
        ListNode *mergeList = new ListNode();
        ListNode *temp = mergeList;

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

        // Append the linked list that is not traverse finish
        if (list1)
        {
            temp->next = list1;
        }

        if (list2)
        {
            temp->next = list2;
        }

        return mergeList->next;
    }

    ListNode *divide(vector<ListNode *> &lists, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }

        if (left == right)
        {
            return lists[left];
        }

        int middle = left + (right - left) / 2;

        ListNode *left_LL = divide(lists, left, middle);
        ListNode *right_LL = divide(lists, middle + 1, right);

        return merge(left_LL, right_LL);
    }

  public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        // Edge case
        // if (lists.empty())
        // {
        //     return nullptr;
        // }
        //
        // for (int i{1}; i < lists.size(); i++)
        // {
        //     lists[0] = merge(lists[0], lists[i]);
        // }
        //
        // return lists[0];

        return divide(lists, 0, lists.size() - 1);
    }
};

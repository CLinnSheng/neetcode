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
 * Remove nth node from the list
 * We can traverse the list first and get the size, so we can know which node to delete
 * */
class Solution
{
  public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int size{};

        ListNode *temp = head;
        while (temp)
        {
            size++;
            temp = temp->next;
        }

        if (size - n == 0)
        {
            return head->next;
        }

        temp = head;
        // Now we will find the node before the deleted node
        int node_before = size - n;
        while (node_before--)
        {

            if (node_before == 0)
            {
                temp->next = temp->next->next;
                break;
            }

            temp = temp->next;
        }

        return head;
    }
};

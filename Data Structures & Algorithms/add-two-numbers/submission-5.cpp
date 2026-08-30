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
 * Return the sum of 2 numbers in a linked list
 * Having a pointer track each link list
 * Key thing is the first number in the list is actualy the last in the actual num
 * for instance 3 -> 2 -> 1 -> == 123
 * So we dont need to do anythign for it. Another important thing is size of l1 is not equal to l2, we need to handle it
 * Another thing need to handle is carry. So we need a variable to track the carry
 * */
class Solution
{
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carry{};
        ListNode *sumList = new ListNode();
        ListNode *temp = sumList;

        while (l1 || l2 || carry)
        {
            int sum = carry;
            if (l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            // Check whether is it greater than 10
            carry = sum / 10;
            temp->next = new ListNode(carry ? sum % 10 : sum);

            temp = temp->next;
        }

        return sumList->next;
    }
};

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
Digits are stored in reversed order. eg: number 123 is represented as 3->2->1
Two numbers do not contain leading 0 except number 0 itself

Goal: Return the sum of the two numbers as a linked list

Intuition:
Since the digits are stored in reversed order. So the first node is the least digit
We just need to extra handle when both node add exceed 10
To overcome this we simply just need to have 1 var to store carryOver
Another thing to take note is l1 and l2 is not always the same size so we need to handle this as well
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* answer = new ListNode();
        ListNode* temp{answer};
        int carryOver{};

        // Handle got carryOver or l1 ran out or l2 ran out
        while(l1 || l2 || carryOver)
        {
            int l1Val = l1? l1->val : 0;
            int l2Val = l2? l2->val : 0;
            int sum{l1Val + l2Val + carryOver};

            int digit{sum % 10};
            carryOver = sum / 10;

            temp->next = new ListNode(digit);
            temp = temp->next;

            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        return answer->next;
    }
};

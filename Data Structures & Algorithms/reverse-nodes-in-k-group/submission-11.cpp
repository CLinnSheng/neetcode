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
 * Reverse the linked list in K Group
 * Brute force way is just simply split the linked list  into k group then only reverse
 * So we need the Kth node in order to get the first node of the next group
 * This will cost O(N * K)
 * how can we do it in 1 pass?
 * */
class Solution
{
  public:
    ListNode *getKthNode(ListNode *node, int k)
    {
        while (node && k)
        {
            node = node->next;
            k--;
        }

        return node;
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (k == 1 || head == nullptr)
        {
            return head;
        }

        ListNode *ans = new ListNode(0, head);
        ListNode *prevGrpNode = ans; // Last node of the previous group

        while (true)
        {
            ListNode *kthNode = getKthNode(prevGrpNode, k);

            // Base Case when not enough nodes in the group
            if (kthNode == nullptr)
            {
                break;
            }

            // Reverse it
            ListNode *currNode = prevGrpNode->next;
            ListNode *nextGrpNode = kthNode->next;
            ListNode *prev = nextGrpNode; // So the prev node is actually starts from the first node of the next group,
                                          // can think of it as a cycle

            while (currNode != nextGrpNode)
            {
                ListNode *temp = currNode->next;
                currNode->next = prev;
                prev = currNode;
                currNode = temp;
            }

            // Update the prevGrp to the last node in current group
            ListNode *temp = prevGrpNode->next;
            // Relink the last node of previous group to the new first node of current group
            prevGrpNode->next = kthNode;
            prevGrpNode = temp;
        }

        return ans->next;
    }
};

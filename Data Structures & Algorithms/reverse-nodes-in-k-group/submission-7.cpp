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
 * Reverse the nodes in groups of k size. Only reverse if it has exactly k size
 * So the problem here is before reversing the nodes, we need to check whether can we have k nodes or not.
 * If dont have we can just simply return it
 * Otherwise we need to reverse it and relink the link list
 * Brute force way will just simply check how many groups are inside, then we just iteratively reverse it and relink
 * Need a helper method that can help us to get the kth node in every group
 * Time Complexity: O(m * k)
 * - m is the number of group
 * - k
 * */
class Solution
{
    ListNode *getKthNode(ListNode *node, int k)
    {
        while (node && k)
        {
            node = node->next;
            k--;
        }

        return node;
    }

  public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        // Base Case
        if (k == 1 || head == nullptr)
        {
            return head;
        }

        ListNode *ans = new ListNode(0, head);
        ListNode *prevGrp = ans;

        // The breaking point is when we couldnt get the kth node in the group
        while (true)
        {
            ListNode *groupKthNode = getKthNode(prevGrp, k);

            // Break when we out of group of k
            if (groupKthNode == nullptr)
            {
                break;
            }

            // Reverse the linked list
            ListNode *currNode = prevGrp->next;
            ListNode *nextGrpNode = groupKthNode->next;
            ListNode *prev = nextGrpNode;

            while (currNode != nextGrpNode)
            {
                ListNode *temp = currNode->next;
                currNode->next = prev;
                prev = currNode;
                currNode = temp;
            }

            // Relink the group of k node with its prev and next group
            ListNode *temp = prevGrp->next;
            prevGrp->next = groupKthNode;
            prevGrp = temp;
        }

        return ans->next;
    }
};

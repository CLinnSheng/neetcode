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
Goal: Return the linkedlist of the reverseKGroup

Intuition:
Brute force way will be reverse the linked list group by group
Time & Space Complexity: O(N)

But can we do it inplace?
We need information of the tail of the prev group so that we can link the new reversed group head to the prev group tail

*/
class Solution {
private:
    // helper function to get the lastnode in the group of k
    ListNode* helper(ListNode* curr, int k)
    {
        while (k && curr)
        {
            curr = curr->next;
            k--;
        }
        return curr;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if (head == nullptr || k == 1)
            return head;

        ListNode* answer = new ListNode(0, head);
        ListNode* prevGroup = answer;

        while (true)
        {
            ListNode* groupLastNode = helper(prevGroup, k);

            // Base Case
            if (groupLastNode == nullptr)
                break;

            ListNode* nextGroupFirstNode = groupLastNode->next;
            
            ListNode* currNode = prevGroup->next;
            ListNode* prevNode = nextGroupFirstNode; // Because we reverseing so the last node prev will be this

            while (currNode != nextGroupFirstNode)
            {
                ListNode* temp = currNode->next;
                currNode->next = prevNode;
                prevNode = currNode;
                currNode = temp;
            }

            // update the prevGroup 
            ListNode* temp = prevGroup->next;
            prevGroup->next = groupLastNode;
            prevGroup = temp;
        }

        return answer->next;
    }
};

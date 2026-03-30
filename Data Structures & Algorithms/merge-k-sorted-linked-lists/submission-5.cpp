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
Goal: Return the sorted linked list

Intuition:
The k linked lists are all in ascending order?
How can we make use of this property?
The brute force way will be having a pointer at each linkedlists and compare all the pointer for every iteration
Or more straight forward  will be directly merged them and sort them
Time Complexity: O(n lg k)

Another approach is by using divide and conquer.
We keep merge it 2 by 2 until only left 1 linkedlist
*/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        // Brute Force
        std::vector<int> nodes;
        for (auto list : lists)
        {
            while (list)
            {
                nodes.emplace_back(list->val);
                list = list->next;
            }
        }

        std::sort(nodes.begin(), nodes.end());
        ListNode* answer = new ListNode();
        ListNode* temp = answer;
        for (const auto& node : nodes)
        {
            temp->next = new ListNode(node);
            temp = temp->next;
        }
        return answer->next;
    }
};

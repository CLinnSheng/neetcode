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
private:
    ListNode* merge(ListNode* node1, ListNode* node2)
    {
        if (node1 == node2 && node2 == nullptr)
            return nullptr;
        if (node1 && node2 == nullptr)
            return node1;
        if (node1 == nullptr && node2)
            return node2;

        ListNode* mergeList = new ListNode();
        ListNode* temp = mergeList;
        while (node1 && node2)
        {
            if (node1->val > node2->val)
            {
                temp->next = new ListNode(node2->val);
                node2 = node2->next;
            }
            else
            {
                temp->next = new ListNode(node1->val);
                node1 = node1->next;
            }

            temp = temp->next;
        }

        // In case 1 linkedlist ran out first
        if (node1 && node2 == nullptr)
            temp->next = node1;
        if (node1 == nullptr && node2)
            temp->next = node2;

        return mergeList->next;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        // Brute Force
        // std::vector<int> nodes;
        // for (auto list : lists)
        // {
        //     while (list)
        //     {
        //         nodes.emplace_back(list->val);
        //         list = list->next;
        //     }
        // }

        // std::sort(nodes.begin(), nodes.end());
        // ListNode* answer = new ListNode();
        // ListNode* temp = answer;
        // for (const auto& node : nodes)
        // {
        //     temp->next = new ListNode(node);
        //     temp = temp->next;
        // }
        // return answer->next;

        int size = lists.size();

        if (size == 0)
            return nullptr;

        while (size > 1)
        {
            for (int i{}; i < size / 2; i++)
                lists[i] = merge(lists[i], lists[size - i - 1]);

            size = (size + 1) / 2; // In case odd number
        }

        return lists[0];
    }
};

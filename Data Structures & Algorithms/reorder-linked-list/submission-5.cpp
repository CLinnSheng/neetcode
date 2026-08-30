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

class Solution {
public:
    void reorderList(ListNode* head) {
       // Brute force solution will just simply store all the nodes in an array then reorder it 
        ListNode* temp = head;
        vector<ListNode*> arr;

        while (temp)
        {
            arr.push_back(temp);
            temp = temp->next;
        }

        vector<ListNode*> newOrder;
        int left = 0, right = arr.size() - 1;
        while (left <= right)
        {
            if (left == right)
            {
                newOrder.push_back(arr[left]);
            }

            newOrder.push_back(arr[left++]);
            newOrder.push_back(arr[right--]);
        }

        temp = head;
        // relink the list from the newOrder
        for (int i{1}; i < newOrder.size(); i++)
        {
            temp->next = newOrder[i];
            temp = temp->next;
        }

        temp->next = nullptr;
    }
};

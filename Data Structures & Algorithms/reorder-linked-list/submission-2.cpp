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
struct Comparator
{
    bool operator()(const ListNode* A, const ListNode* B)
    {
        return A->val < B->val;
    }
};
class Solution {
public:
    void reorderList(ListNode* head) {
        // Brute force will just simply store all the values in an array
        // Then reconstruct the whole LL again
        // If you observe from how the reorder is being done, alternating first and last pointer
        // But this still quite efficeint O(n)
        std::vector<ListNode*> nodes;
        ListNode* temp = head;

        while (temp)
        {
            nodes.push_back(temp);
            temp = temp->next;
        }

        int n = nodes.size();
        int left{}, right{n - 1};
        std::vector<ListNode*> order_nodes;

        while (left <= right)
        {
            if (left == right)
            {
                order_nodes.push_back(nodes[left]);
                break;
            }

            order_nodes.push_back(nodes[left++]);
            order_nodes.push_back(nodes[right--]);
        }

        // Reconstruct the node
        head->next = nullptr;
        for (int i{1}; i < n; i++)
        {
            head->next = order_nodes[i];
            head = head->next;
        }

        // Then end the last node
        head->next = nullptr;
    }

};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

/*
 * Create a new list from the original list
 * New list must not point to the nodes in the original list
 * We can just iterate through the link list and create the copy while on go. But theres a problem which is the random
 * ptr It will point randomly to any node, what if point to a node that we never create before?
 * So we will just create a map that maps the old node to the new node. So we can easily get the copy node in O(1)
 * So we can just use the same new_node for any ptr.
 * */
#include <unordered_map>
class Solution
{
  public:
    Node *copyRandomList(Node *head)
    {
        std::unordered_map<Node *, Node *> mp;
        Node *temp = head;
        while (temp)
        {
            mp[temp] = new Node(temp->val);
            temp = temp->next;
        }

        Node *new_head = mp[head];
        Node *copy = new_head;
        while (head)
        {
            copy->next = mp[head->next];
            copy->random = mp[head->random];

            copy = copy->next;
            head = head->next;
        }

        return new_head;

        // If dont have random ptr
        // Node *new_head = new Node(head->val);
        // Node *copy = new_head;
        // head = head->next;
        // while (head)
        // {
        //     Node *new_node = new Node(head->val);
        //     copy->next = new_node;
        //     copy = copy->next;
        //
        //     head = head->next;
        // }
        //
        // return new_head;
    }
};

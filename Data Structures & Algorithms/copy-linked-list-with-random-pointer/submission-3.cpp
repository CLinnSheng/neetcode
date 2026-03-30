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
Given the head of a linked list of length n.
Each node contains an additional pointer random, point to any node in the list or null
Goal: Create a deep copy.
Deep copy should consists of exactly n new nodes, each including:
i. Original val of the copied node
ii. Next pointer to the new node corresponding to the next pointer of the original pointer.
iii. Random pointer to the new node corresponing to the random pointer of the original node
** None of the pointers in the new list should point to nodes in the original list.

Intuition:
We can easily create a new set of node just iterating through the existing node if dont have the random pointer.
Then how can we solve it? The random pointer might point to any node which maybe havent created or created.
Ok how about we assign the random pointer later on? We can use a hash map to store the address of the node with val as the key
if key is distinct. Since we  cant guarantee key is distinct how about we striaght use
old node mapping to new node? So we basically need to access the new node through the old node
Time Complexity: O(n)
*/
class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        std::unordered_map<Node*, Node*> map;
        Node* oldNode{head};
        // First iteration create new node first
        while (oldNode)
        {
            Node* newNode = new Node(oldNode->val);
            map[oldNode] = newNode;
            oldNode = oldNode->next;
        }

        // Second iteration since all new nodes are built, can point properly to the corrected node
        // easily through hash map by using old node informaiton
        oldNode = head;
        while (oldNode)
        {
            map[oldNode]->next = map[oldNode->next];
            map[oldNode]->random = map[oldNode->random];
            oldNode = oldNode->next;
        }
        return map[head];
    }
};

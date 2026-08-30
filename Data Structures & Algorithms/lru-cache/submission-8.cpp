/*
 * Each method must be in O(1)
 * Every time exceed the capacity, we will remove the least recently used.
 * And everytime we put if is an eixsting item, we update it to be the newest.
 * What data structure we can use? Linked List
 * Let make the front as the least recently used and back is the newest
 * So we want to easily access the first element and the last element to ease inserting and removing from the linked
 * list Can have 2 Node as the boundary
 *
 * We also need a hashmap to map the key to the node, so we can access the node in the linked list in O(1)
 * */
#include <unordered_map>
struct Node
{
    Node *next;
    Node *prev;
    int key, val;

    Node() : next{nullptr}, prev{nullptr}
    {
    }

    Node(int key, int val) : next{nullptr}, prev{nullptr}, key{key}, val{val}
    {
    }

    Node(int key, int val, Node *next, Node *prev) : next{next}, prev{prev}, key{key}, val{val}
    {
    }
};

class LRUCache
{
    int capacity, size;
    Node *left, *right;
    std::unordered_map<int, Node *> map;

  private:
    void remove(Node *node)
    {
        // Get the node before and after then relink
        Node *prev = node->prev;
        Node *next = node->next;

        delete node;

        prev->next = next;
        next->prev = prev;
    }

    void insert(Node *node)
    {
        // Insert into the back
        Node *prev = right->prev;
        prev->next = node;

        node->next = right;
        node->prev = prev;

        right->prev = node;
    }

  public:
    LRUCache(int capacity) : capacity{capacity}
    {
        left = new Node(0, 0);
        right = new Node(0, 0);

        left->next = right;
        right->prev = left;
    }

    int get(int key)
    {
        if (map.find(key) != map.end())
        {
            Node *node = map[key];
            int val = node->val;

            // Update its frequency as well
            // Remove from the linked list and insert into the back
            remove(node);

            Node *new_node = new Node(key, val);
            map[key] = new_node;

            insert(new_node);

            return val;
        }

        return -1;
    }

    void put(int key, int value)
    {
        // Few cases
        // 1. Existing Node
        // 2. Non existing node & enough capacity
        // 3. Non existing node & not enough capacity

        // Existing Node
        if (map.find(key) != map.end())
        {
            // Remvoe from the linked list and push it to the back
            // Get the node
            Node *delete_node = map[key];
            remove(delete_node);

            // remove from the map
            map.erase(key);

            Node *new_node = new Node(key, value);
            map[key] = new_node;
            insert(new_node);
        }
        else
        {
            // Enough Capacity
            if (map.size() < capacity)
            {
                Node *new_node = new Node(key, value);
                map[key] = new_node;
                insert(new_node);
            }
            // Not enough capacity
            else
            {
                // Remove the LRU Node / front node & map also
                Node *delete_node = left->next;
                map.erase(delete_node->key);
                remove(delete_node);

                Node *new_node = new Node(key, value);
                map[key] = new_node;
                insert(new_node);
            }
        }
    }
};

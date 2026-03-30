/*
Intuition:
We need to always keep track of the least recently used key
Every get and put will update the least recently used.
So thats mean every operation we need to update the least recently used
For the key value pair, we can use a hash map to store it.

*/
class LRUCache {
private:
    struct Node
    {
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int k, int v, Node* n = nullptr, Node* p = nullptr) :
        key(k), val(v), next(n), prev(n) {}
    };

    void remove(Node* node)
    {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    void insert(Node* node)
    {
        // Append to the end
        Node* prev = right->prev;
        prev->next = node;
        node->prev = prev;
        node->next = right;
        right->prev = node;
    }

public:
    int capacity;
    std::unordered_map<int, Node*> map;
    Node* left;
    Node* right;
    LRUCache(int capacity) 
    {
        this->capacity = capacity;  
        left = new Node(0, 0);      
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if (map.count(key))
        {
            // Remove it and append to the end
            auto node{map[key]};
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (map.count(key)) // Update the value of existing key, so need to update it, as it will on the top
            remove(map[key]);
        // Handle max capcity
        Node* newNode = new Node(key, value);
        map[key] = newNode;
        insert(newNode);

        if (map.size() > capacity)
        {
            // Remove the least frequently used
            Node* least = left->next;
            remove(least);
            map.erase(least->key);
            delete least;
        }
    }
};

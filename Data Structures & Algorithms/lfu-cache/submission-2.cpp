/*
Intuition:
We need to always keep track the least frequently used.
So this wil be a little bit similar to LRU but need with a little bit of tweak
We need a data structure that can easily access the least frequently used node.
*/
class LFUCache {
private:
    struct Node
    {
        int val; // Storing the key
        Node* next;
        Node* prev;
        Node(int v = 0, Node* n = nullptr, Node* p = nullptr) :
        val(v), next(n), prev(p) {}
    };

    // To solve edge cases where some node has the same freq, so we will just remove from
    // the left which is the LRU
    struct LinkedList
    {
        Node* left;
        Node* right;
        unordered_map<int, Node*> map;

        LinkedList()
        {
            left = new Node();
            right = new Node();
            left->next = right;
            right->prev = left;
        }

        ~LinkedList()
        {
            while (left->next != right)
            {
                Node* temp = left->next;
                left->next = temp->next;
                delete temp;
            }

            delete left;
            delete right;
        }

        // returning the number of node in the linkedlist
        int size()
        {
            return map.size();
        }

        void pop(int val)
        {
            if (map.find(val) != map.end())
            {
                Node* node = map[val];
                Node* next = node->next;
                Node* prev = node->prev;
                next->prev = prev;
                prev->next = next;
                map.erase(val);
                delete node;
            }
        }

        int popLeft()
        {
            int res = left->next->val;
            pop(res);
            return res;
        }

        void pushRight(int val)
        {
            Node* node = new Node(val, right, right->prev);
            right->prev->next = node;
            right->prev = node;
            map[val] = node;
        }

    };

    // For updating the cache for storing the LFU
    void counter(int key)
    {
        int cnt = countMap[key];
        countMap[key]++;

        // Remove it from cnt and add it to cnt + 1
        listMap[cnt]->pop(key);

        if (listMap.find(cnt + 1) == listMap.end())
            listMap[cnt + 1] = new LinkedList();

        listMap[cnt + 1]->pushRight(key);

        if (cnt == lfuCount && listMap[cnt]->size() == 0)
            lfuCount++;
    }

    int capacity;
    int lfuCount; // track the current LFU linkedlist
    unordered_map<int, int> valMap; // Mapping key to val
    unordered_map<int, int> countMap; // Mapping key to count

    // This map will basically store all the nodes with a specific count
    unordered_map<int, LinkedList*> listMap; // Mapping count to linkedlist
public:
    LFUCache(int capacity) : capacity{capacity}, lfuCount{0} {
        listMap[0] = new LinkedList();
    }
    
    int get(int key) {
        if (valMap.find(key) == valMap.end())
            return -1;

        // Update the LFU cache
        counter(key); 
        return valMap[key];
    }
    
    void put(int key, int value) 
    {
        if (capacity == 0)
            return;

        // reach maximum capacity and remove the most left node from the current LFU linkedlist
        if (valMap.size() == capacity && valMap.find(key) == valMap.end())
        {
            int removeNode = listMap[lfuCount]->popLeft();
            valMap.erase(removeNode);
            countMap.erase(removeNode);
        }

        valMap[key] = value;

        // if new element then need to update LFU
        if (countMap.find(key) == countMap.end())
        {
            countMap[key] = 0;
            listMap[0]->pushRight(key);
            lfuCount = 0;
        }

        counter(key);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
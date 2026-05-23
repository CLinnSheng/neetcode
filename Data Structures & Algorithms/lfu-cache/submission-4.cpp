/*
 * Design LFU Cache
 * So over here we know that frequency of each key get accessed matter
 * So we need a way of keeping track the frequency of each key.
 * And another thing that matters a lot as well, is if A & B is get accessed one time and how do we decide which 1 to
 * remove? --> Use FIFO concept over here
 *
 * Which Data Structure should i use?
 * - Is kinda similar to LRU cache, over there we dont need to keep track freq we only keep inserting the new node in
 * the front and remove it if exist
 * We can use linked list
 * So a few thing we need to store and easily get access
 * The linkedlist of each frequecny
 * The value of the key
 *
 * */
#include <cstddef>
#include <unordered_map>
struct Node
{
    Node *prev;
    Node *next;
    int val;

    Node(int val = 0, Node *prev = nullptr, Node *next = nullptr) : val(val), prev(prev), next{next}
    {
    }
};

// The order of nodes in the LL does matter **IMPORTANT**
// Will be storing the frequency map to each LL
struct LinkedList
{
    // Boundary pointer so can easily access the front and the end
    Node *left;
    Node *right;
    // O(1) access of the node
    std::unordered_map<int, Node *> nodes;

    /*
     * A few helper method that we need over here
     * - Removing the specific node
     * - Pushing in the front/left
     * - Popping from the back/right
     * - Size of LL
     * */
    LinkedList()
    {
        left = new Node();
        right = new Node();
        left->next = right;
        right->prev = left;
    }

    ~LinkedList()
    {
        Node *curr = left;
        while (curr != nullptr)
        {
            Node *temp = curr->next;
            delete curr;
            curr = temp;
        }
    }

    size_t size()
    {
        return nodes.size();
    }

    // Removing the specific node
    // Why we need this? because if we replace this key or access it we need to increase its count, so it no longer
    // belong to this freq LL
    void pop(int key)
    {
        // Finding the node
        // Remove it
        if (nodes.find(key) != nodes.end())
        {
            // Get the node
            Node *node = nodes[key];

            // Remove the node and reconnecting the LL
            Node *prev_node = node->prev;
            Node *next_node = node->next;

            prev_node->next = next_node;
            next_node->prev = prev_node;

            nodes.erase(key);
            delete node;
        }
    }

    // Helper method to insert new into the LL
    void pushLeft(int key)
    {
        Node *node = new Node(key);

        // Insert into LL
        Node *next_node = left->next;

        node->next = next_node;
        node->prev = left;

        left->next = node;
        next_node->prev = node;

        nodes[key] = node;
    }

    // Pop the least recently used nodes from the LL
    // Return the key of the node
    int popRight()
    {
        int key = right->prev->val;

        // Reuse the pop method
        pop(key);

        return key;
    }
};
class LFUCache
{
    int capacity;
    int lfuCount;                                 // Tracking the current min freq
    std::unordered_map<int, int> keyVal;          // Getting the value if exist
    std::unordered_map<int, int> keyFreq;         // Mapping the key to the freq of the LL it belongs
    std::unordered_map<int, LinkedList *> freqLL; // Mapping the frequency of each LL

  public:
    LFUCache(int capacity) : capacity(capacity), lfuCount(0)
    {
        freqLL[0] = new LinkedList();
    }

    int get(int key)
    {
        // Check whether the node exist or not
        // If exist then update its count
        if (keyVal.find(key) == keyVal.end())
        {
            return -1;
        }

        updateLFUCache(key);
        return keyVal[key];
    }

    /*
     * Upate the value of the key if present, or insert the key if not present
     * When reach capacity, it should replace the least frequently used
     * */
    void put(int key, int value)
    {
        // Base Case
        if (capacity == 0)
        {
            return;
        }

        // 2 Cases
        // 1. Capacity Reach Maximum
        // 2. Still has capacity left or existing key just update its freq

        // First we check the capacity first if max then we remove the LFU node
        if (keyVal.size() == capacity && keyVal.find(key) == keyVal.end())
        {
            int removeNode_key = freqLL[lfuCount]->popRight();

            // Remove the node first from the cache
            keyVal.erase(removeNode_key);
            keyFreq.erase(removeNode_key);
        }

        // Inserting the new node
        // Updating the cache
        keyVal[key] = value;

        // Handle new element --> freq is 0 and then this will be the LFU node
        // Update the lfuCount to 0 first [updateLFUCache helper method will increase it to 1]
        if (keyFreq.find(key) == keyFreq.end())
        {
            lfuCount = 0;
            freqLL[0]->pushLeft(key);
            keyFreq[key] = 0;
        }

        updateLFUCache(key);
    }

    // Helper method to update the cache
    // Update the node to its dedicated freq LL & also check whether do we need to incrase the LFUCount or not
    void updateLFUCache(int key)
    {
        // Get the original count then increase it
        int cnt = keyFreq[key];

        keyFreq[key]++;
        // Popping from the linkedlist that hold this freq then update to the new linkedlist with the new count
        freqLL[cnt]->pop(key);

        // Check whether is it a new linkedlist or not
        if (freqLL.find(cnt + 1) == freqLL.end())
        {
            freqLL[cnt + 1] = new LinkedList();
        }

        // Insert into it
        freqLL[cnt + 1]->pushLeft(key);

        // Updating the LFUCount
        // IMPORTANT need to check whether the linkedlist of the current LFU is empty or not
        if (cnt == lfuCount && freqLL[cnt]->size() == 0)
        {
            this->lfuCount++;
        }
    }
};
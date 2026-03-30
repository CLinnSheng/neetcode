/*
Implement a linked list data structure
*/
class MyCircularQueue 
{
private:
    struct Node
    {
        int val;
        Node* next;
        Node* prev;

        Node(int v, Node* n = nullptr, Node* p = nullptr) : val(v), next(n), prev(p) {}
    };

    int space;
    Node* left; // Start of the linked list
    Node* right; // End of the linked list

public:
    MyCircularQueue(int k) 
    {
        space = k;
        left = new Node(0);
        right = new Node(0, nullptr, left);
        left->next = right;
    }
    
    // Push to the back
    bool enQueue(int value) {
        if (isFull())
            return false;

        Node* curr = new Node(value, right, right->prev);
        right->prev->next = curr;
        right->prev = curr;
        space--;

        return true;
    }
    
    // Pop from the front
    bool deQueue() {
        if (isEmpty())
            return false;

        Node* curr = left->next;
        left->next = curr->next;
        left->next->prev = left;
        delete curr;
        space++;

        return true;
    }
    
    int Front() {
        return isEmpty()? -1 : left->next->val;
    }
    
    int Rear() {
        return isEmpty()? -1 : right->prev->val;
    }
    
    bool isEmpty() {
        return left->next == right;
    }
    
    bool isFull() {
        return space == 0;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
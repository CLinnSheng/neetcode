class MyStack {
public:
    std::queue<int> queue;
    MyStack() {
        queue = std::queue<int>();
    }
    
    void push(int x) {
        queue.push(x);
    }
    
    int pop() {
        std::queue<int> temp = queue;
        int size = temp.size();

        queue = std::queue<int>();
        while (size - 1)
        {
            queue.push(temp.front());
            temp.pop();
            size--;
        }

        return temp.front();
    }
    
    int top() {
        std::queue<int> temp = queue;

        int element{};
        while (!temp.empty())
        {
            element = temp.front();
            temp.pop();
        }

        return element;        
    }
    
    bool empty() {
        return queue.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
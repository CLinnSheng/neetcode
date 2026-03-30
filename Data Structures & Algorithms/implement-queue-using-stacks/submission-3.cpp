class MyQueue {
public:
    std::stack<int> s1, s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    // Average Time Complexity make it O(1)
    int pop() {
        if (s2.empty())
        {
            // Move all element to s2
            while (!s1.empty())
            {
                int val = s1.top();
                s1.pop();
                s2.push(val);
            }
        }
        int val = s2.top();
        s2.pop();
        return val;
    }
    
    int peek() {
        if (s2.empty())
        {
            // Move all element to s2
            while (!s1.empty())
            {
                int val = s1.top();
                s1.pop();
                s2.push(val);
            }
        }
        int val = s2.top();
        return val;      
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
class MyQueue {
public:
    std::stack<int> stack;
    MyQueue() {
        
    }
    
    void push(int x) {
        stack.push(x);
    }
    
    int pop() {
        std::stack<int> temp;
        while(!stack.empty())
        {
            temp.push(stack.top());
            stack.pop();
        }

        int val = temp.top();
        temp.pop();

        while(!temp.empty())
        {
            stack.push(temp.top());
            temp.pop();
        }

        return val;
    }
    
    int peek() {
        std::stack<int> temp;

        while(!stack.empty())
        {
            temp.push(stack.top());
            stack.pop();
        }

        int val = temp.top();

        while(!temp.empty())
        {
            stack.push(temp.top());
            temp.pop();
        }
        return val;        
    }
    
    bool empty() {
        return stack.empty();
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
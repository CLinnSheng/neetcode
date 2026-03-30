class MyQueue {
public:
    std::stack<int> stack;
    MyQueue() {
    }
    
    void push(int x) {
        stack.push(x);
    }
    
    int pop() {
        std::stack<int> temp(stack);

        stack = std::stack<int>();

        while (!temp.empty())
        {
            stack.push(temp.top());
            temp.pop();
        }

        int res = stack.top();
        stack.pop();

        temp = stack;
        stack = std::stack<int>();

        while (!temp.empty())
        {
            stack.push(temp.top());
            temp.pop();
        }

        return res;
    }
    
    int peek() {
        std::stack<int> temp(stack);
        std::stack<int> temp2;
        int size(stack.size());


        while (!temp.empty())
        {
            temp2.push(temp.top());
            temp.pop();
        }

        return temp2.top();
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
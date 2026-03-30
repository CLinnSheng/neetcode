class MinStack {
public:
    std::stack<int> stack;
    std::stack<int> minStack;
    MinStack() {
        stack = std::stack<int>();
        minStack = std::stack<int>();
    }
    
    void push(int val) {
        stack.push(val);
        if (minStack.empty())
            minStack.push(val);
        else
        {
            int temp{minStack.top()};
            minStack.push(temp > val? val : temp);
        }
    }
    
    void pop() {
        stack.pop();
        minStack.pop();
    }
    
    int top() {
        return stack.top();
    }
    
    // Have a dedicated stack that storing the min element at every single time
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
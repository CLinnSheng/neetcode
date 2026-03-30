class MinStack {
public:
    std::stack<int> stack1, stack2;
    MinStack() {
        // Have 1 stack store all elements
        // Another stack store the minElement of the current stack
    }
    
    void push(int val) {
        stack1.push(val);
        if (stack2.empty())
        {
            stack2.push(val);
        }
        else
        {
            int top = stack2.top();
            stack2.push(std::min(top, val));
        }
    }
    
    void pop() {
        stack1.pop();
        stack2.pop();
    }
    
    int top() {
        return stack1.top();
    }
    
    int getMin() {
        return stack2.top();
    }
};

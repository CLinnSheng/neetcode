/*
 * Make each function O(1)
 * Brute force solution will result in O(n)
 * How can we make it O(1)? means that we need to directly pop out of the stack
 * So we need a dedicated stack for the min, the min stack will just basically keep track of the current min from the
 * original stack
 * */
#include <stack>
class MinStack
{
    std::stack<int> stack, stack_min;

  public:
    MinStack()
    {
    }

    void push(int val)
    {
        stack.push(val);

        if (stack_min.empty())
        {
            stack_min.push(val);
        }
        else
        {
            stack_min.push(std::min(val, stack_min.top()));
        }
    }

    void pop()
    {
        stack.pop();
        stack_min.pop();
    }

    int top()
    {
        return stack.top();
    }

    int getMin()
    {
        return stack_min.top();
    }
};

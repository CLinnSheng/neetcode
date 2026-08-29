#include <cctype>
#include <stack>
#include <string>
#include <vector>
using std::vector, std::string;
/*
 * Evaluate the value of the expression
 * So when we encouter a sign after 2 number, then just apply it only
 * In order to store previous information in such order, we need a stack
 * */
class Solution
{
  public:
    int evalRPN(vector<string> &tokens)
    {
        std::stack<int> stack;
        for (const auto &token : tokens)
        {
            if (token.length() >= 2 || std::isdigit(token[0]))
            {
                stack.push(std::stoi(token));
            }
            else
            {
                int num2 = stack.top();
                stack.pop();
                int num1 = stack.top();
                stack.pop();

                if (token == "+")
                {
                    stack.push(num1 + num2);
                }
                else if (token == "-")
                {
                    stack.push(num1 - num2);
                }
                else if (token == "*")
                {
                    stack.push(num1 * num2);
                }
                else
                {
                    stack.push(num1 / num2);
                }
            }
        }

        return stack.top();
    }
};

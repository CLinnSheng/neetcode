/*
So basically we only do the computation whenever we face an operator
So in order to corectly implement the operator to the correct number,
we need a stack to holds the value at the correct order
*/
class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        std::deque<int> stack;

        for (const auto& token : tokens)
        {
            if (token != "+" && token != "-" && token != "*" && token != "/")
                stack.emplace_back(std::stoi(token));
            else
            {
                int num2{stack.back()};
                stack.pop_back();
                int num1{stack.back()};
                stack.pop_back();

                if (token == "+")
                    stack.emplace_back(num1 + num2);
                else if (token == "-")
                    stack.emplace_back(num1 - num2);
                else if (token == "*")
                    stack.emplace_back(num1 * num2);
                else if (token == "/")
                    stack.emplace_back(num1 / num2);
                
            }
        }
        return stack.back();
    }
};
/*
Encoding rule: k[encoded_string], then repeated by k times.
K --> +ve

Intuition:
We need to think of algorithm that will always solve the most innermost bracket to the outermost
One important key observatoin is the format of encoding rule.
so whenever we face this pattern only have to do encoding.
So we will basically store everything in a stack, because we need the information in the past and in the correct sequence
Only pop it whne the encoding finishes which is whenever we face ']'
Time Complexity: O(n)
*/

string operator*(const std::string& str, int digit)
{
    std::stringstream s;
    while (digit--)
        s << str;

    return s.str();
}

class Solution {
public:
    string decodeString(string s) 
    {
        std::deque<std::string> stack;
        std::string currStr;

        for (const char& c : s)
        {
            if (c == ']')
            {
                // Then take all the alphabets
                std::string str;
                while (!stack.empty() && stack.back() != "[")
                {
                    str = stack.back() + str;
                    stack.pop_back();
                }

                // remove '['
                stack.pop_back();

                // Then process the digits.
                std::string digit;
                while (!stack.empty() && isdigit(stack.back()[0]))
                {
                    digit = stack.back() + digit;
                    stack.pop_back();
                }

                int digits = std::stoi(digit);
                str = str * digits;

                stack.push_back(str);
            }
            else
                stack.push_back(std::string(1, c));

        }       

        std::string ans;
        while (!stack.empty())
        {
            ans += stack.front();
            stack.pop_front();
        } 

        return ans;
    }
};
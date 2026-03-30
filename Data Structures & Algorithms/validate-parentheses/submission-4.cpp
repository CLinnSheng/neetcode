/*
Valid String: Every open brack is closed by the same type of closed bracket
and is in the ocrrect order.

Goal: Check whether is it a valid string or not.

Intuition:
We need to check the closed bracket when ther is no more open bracket. And we also
need to track back the previous open bracket havent close yet.
So the data structure come in mind is stack

Time Complexity: O(n)
*/
class Solution {
public:
    bool isValid(string s) 
    {
        std::deque<char> stack;
        std::unordered_map<char, char> mapping{{')', '('}, {']', '['}, {'}', '{'}};

        for (const char& ch : s)
        {
            std::cout << ch << '\t';
            if (!mapping.count(ch))
                stack.emplace_back(ch);
            else
            {
                // handle edge cases where there is no open bracket in the stack
                if (stack.empty() || mapping[ch] != stack.back())
                    return false;

                stack.pop_back();
            }
        }
        return stack.empty();
    }
};

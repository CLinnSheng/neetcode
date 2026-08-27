/*
Check whether the string is valid or not by making sure every open parenthesis is comes with a close parenthesis
Have a wild card that can be open, close or nothing
Open prenthesis always come before close, so if we encounter a close and then we dont have open anymore then is invalid
This lead us to using stack
And then when should we using the wild card. Since every parenthesis must be use then we only use it if we short of open or close parentheis --> Greedy?
*/
class Solution {
public:
    bool checkValidString(string s) {
        stack<int> open, wildcard;

        for (int i{}; i < s.length(); i++)
        {
            if (s[i] == ')')
            {
                if (open.empty() && wildcard.empty())
                {
                    return false;
                }

                if (open.size())
                {
                    open.pop();
                }
                else if (wildcard.size())
                {
                    wildcard.pop();
                }
            }
            else if (s[i] == '(')
            {
                open.push(i);
            }
            else
            {
                wildcard.push(i);
            }
        }

        // Clear the remaining left parenthesis
        while (open.size() && wildcard.size())
        {
            if (open.top() < wildcard.top())
            {
                open.pop();
                wildcard.pop();
            }
            else
            {
                break;
            }
        }

        return open.empty();
    }
};

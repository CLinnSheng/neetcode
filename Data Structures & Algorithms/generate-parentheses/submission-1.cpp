/*
Generate n pair of parentheses

Intuition:
n --> 2*n of length for each parentheses strings.
We can use dfs & backtracking to try all possible string.
The base cases will be  when closing bracket > opening bracket then we have to  backtrack

*/
class Solution {
public:
    vector<string> generateParenthesis(int n) 
    {
        std::vector<std::string> ans;

        std::function<void(const int&, const int&, std::string)> dfs = [&](const int& openBracket, const int& closeBracket, std::string currStr)
        {
            if (closeBracket > openBracket)
                return;

            if (currStr.length() == 2*n)
            {
                ans.emplace_back(currStr);
                return;
            }

            // Open Bracket
            if (openBracket < n)
                dfs(openBracket + 1, closeBracket, currStr + "(");
            
            dfs(openBracket, closeBracket + 1, currStr + ")");
        };

        dfs(0, 0, "");

        return ans;    
    }
};

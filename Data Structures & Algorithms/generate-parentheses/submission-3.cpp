#include <string>
#include <vector>
using std::vector, std::string;
/*
 * Explore all possible pairs of parentheses
 * Keyword is all possible --> DFS and then backtrack
 * But the problem is how do we determine to go for open or close?
 * We can use the number of open and close bracket to determine.
 *
 * First if open bracket is still left than n we can continue add it, or we can close it.
 * Also close bracket must always smaller or equal to the number of open bracket we currently have
 * */
class Solution
{
  public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        string subset{};

        dfs(n, 0, 0, ans, subset);

        return ans;
    }

    void dfs(const int n, int open, int close, vector<string> &ans, string &subset)
    {
        if (open == n && close == n)
        {
            ans.push_back(subset);
            return;
        }

        // If open bracket smaller than n, continue to add
        if (open < n)
        {
            subset.push_back('(');
            dfs(n, open + 1, close, ans, subset);

            // backtrack
            subset.pop_back();
        }

        // if close smaller than open, we can choose to close
        if (close < open)
        {
            subset.push_back(')');
            dfs(n, open, close + 1, ans, subset);

            subset.pop_back();
        }
    }
};

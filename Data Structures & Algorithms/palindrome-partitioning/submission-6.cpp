#include <string>
#include <string_view>
#include <vector>
using std::vector, std::string;
/*
 * Finding all possible list of palindromic substring
 * Key word is *all possilbe** --> Backtracking
 * So at every index we try to split it if is a palindrom we proceed either we continue to the next index
 * */
class Solution
{
  public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> subset;

        dfs(s, ans, subset, 0);
        return ans;
    }

    bool helper(std::string_view s)
    {
        int left{}, right = s.length() - 1;

        while (left <= right)
        {
            if (s[left] != s[right])
            {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    void dfs(const string &s, vector<vector<string>> &ans, vector<string> &subset, int index)
    {
        // base case
        if (index == s.length())
        {
            ans.push_back(subset);
            return;
        }

        for (int j{index}; j < s.length(); j++)
        {
            string temp = s.substr(index, j - index + 1);

            if (helper(temp))
            {
                subset.push_back(temp);
                dfs(s, ans, subset, j + 1);

                subset.pop_back();
            }
        }
    }
};

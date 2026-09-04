#include <string>
#include <unordered_map>
#include <vector>
using std::vector, std::string;
/*
 * Find all possible letter combinations that digit could represent, can map the number to the numbers
 * */
class Solution
{
  public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
        {
            return {};
        }

        std::unordered_map<char, string> maps;
        maps['2'] = "abc";
        maps['3'] = "def";
        maps['4'] = "ghi";
        maps['5'] = "jkl";
        maps['6'] = "mno";
        maps['7'] = "pqrs";
        maps['8'] = "tuv";
        maps['9'] = "wxyz";

        vector<string> ans;
        string letters{};

        dfs(digits, maps, ans, letters, 0);

        return ans;
    }

    void dfs(const string &digits, std::unordered_map<char, string> &maps, vector<string> &ans, string &letters,
             int index)
    {
        if (index == digits.length())
        {
            ans.push_back(letters);
            return;
        }

        for (const auto ch : maps[digits[index]])
        {
            letters.push_back(ch);
            dfs(digits, maps, ans, letters, index + 1);

            letters.pop_back();
        }
    }
};

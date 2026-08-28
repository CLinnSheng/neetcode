#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using std::vector, std::string;

/*
 * Group the same anagram together
 * One important observation, if we sort all the str that is from the same anagram they will end up with the same str
 * */
class Solution
{
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        // Edge Case
        if (strs.empty())
        {
            return {};
        }

        std::unordered_map<string, vector<string>> map;
        for (const auto &str : strs)
        {
            string temp = str;
            std::sort(temp.begin(), temp.end());
            map[temp].push_back(str);
        }

        vector<vector<string>> ans;
        for (const auto &[key, strings] : map)
        {
            ans.push_back(strings);
        }
        return ans;
    }
};

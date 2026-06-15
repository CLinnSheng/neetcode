#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
/*
 * Return the minimum number of extra characters left over if break up S optimally
 * Problme here is how can we break up S optimally? Brute force way will be trying all possible way of breaking up the S
 * Store the dicitionary in a set
 * */
class Solution
{
  private:
    std::unordered_map<int, int> cache;

    int solution_1(const std::string &s, const std::unordered_set<std::string> &set, const int index)
    {
        // We can further optimize it because if you notice we keep calling this function with the same index

        // Base Case
        if (index == s.length())
        {
            return 0;
        }

        if (cache.find(index) != cache.end())
        {
            return cache[index];
        }

        // Skipping this character
        int ans = 1 + solution_1(s, set, index + 1);

        for (int i{index}; i < s.length(); i++)
        {
            auto subStr = s.substr(index, i - index + 1);

            if (set.find(subStr) != set.end())
            {
                // Split over here
                ans = std::min(ans, solution_1(s, set, i + 1));
            }
        }

        return cache[index] = ans;
    }

  public:
    int minExtraChar(std::string s, std::vector<std::string> &dictionary)
    {
        std::unordered_set<std::string> set(dictionary.begin(), dictionary.end());
        return solution_1(s, set, 0);
    }
};

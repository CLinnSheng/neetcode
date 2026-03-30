#include <algorithm>
#include <string>
#include <vector>

/*
 * Goal: Need to find the longest common prefix among all the string in the arrays
 * If there is no common prefix return ""
 *
 * Intuition:
 * Key observation is not all the strings have the same length, so we need to check all the string
 * with the minimum string in the arrays.
 * Simpler way is straight away compare the longest and shortest
 *
 * Time Complexity: O(nlgn)
 * Space Complexity: O(1)
 * */
class Solution
{
  public:
    std::string longestCommonPrefix(std::vector<std::string> &strs)
    {
        size_t size = strs.size();

        // Base Case
        if (size == 1)
        {
            return strs[0];
        }

        std::sort(strs.begin(), strs.end());
        
        std::string commonPrefix{};
        for (int i{}; i < strs[0].length(); i++)
        {
            if (strs[0][i] != strs[size - 1][i])
            {
                return commonPrefix;
            }

            commonPrefix += strs[0][i];
        }

        return commonPrefix;
    }
};

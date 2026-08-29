#include <string>
#include <unordered_set>
using std::string;
/*
 * To check whether there is repeating characters or not just simply using hash set.  can chick in O(1)
 * We can use sliding window algo to find it, keep expanding if no new character and shrink when we found repeating
 * character
 * */
class Solution
{
  public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.empty())
        {
            return 0;
        }

        int left{}, right{};
        std::unordered_set<char> chars;
        int maxLen{};

        while (right < s.length())
        {
            while (chars.find(s[right]) != chars.end())
            {
                chars.erase(s[left]);
                left++;
            }

            chars.insert(s[right]);
            maxLen = std::max(maxLen, right - left + 1);

            right++;
        }

        return maxLen;
    }
};

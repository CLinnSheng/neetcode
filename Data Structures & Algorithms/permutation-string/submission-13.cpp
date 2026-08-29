#include <string>
#include <unordered_map>
using std::string;
/*
 * Check s2 contains permutation of s1. So order doesnt matter, and what matter is that make sure the substring of s2
 * has the exact same freq as s1.
 * So to easily check just simply use hashamp to store the freq of each char
 * We can use sliding window algo to find out the substring
 * Condition to move the string when the new char is part of s1, shrink it when we it is not part of s1
 * */
class Solution
{
  public:
    bool checkInclusion(string s1, string s2)
    {
        // Base case
        if (s1.length() > s2.length())
        {
            return false;
        }

        std::unordered_map<char, int> map1, map2;
        for (const auto ch : s1)
        {
            map1[ch]++;
        }

        int left{}, right{};
        while (right < s2.length())
        {
            char ch = s2[right];

            // Need to reset the window instead of shrinking because the current char is not what we want
            if (map1.find(ch) == map1.end())
            {
                map2.clear();
                left = right + 1;
            }
            else
            {
                while (map2[ch] + 1 > map1[ch])
                {
                    map2[s2[left]]--;
                    left++;
                }

                map2[ch]++;
                if (map1 == map2)
                {
                    return true;
                }
            }

            right++;
        }
        return false;
    }
};

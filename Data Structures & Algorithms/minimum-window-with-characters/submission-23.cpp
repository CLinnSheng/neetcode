#include <climits>
#include <string>
#include <unordered_map>
using std::string;
/*
 * Return the shortest substring of s such that every character in t including duplicates is present in the substring
 * We can use a sliding window algo to find it.
 * So when do we expand or shrink?
 * We expand it when we couldnt find the substring. We shrink it when we find the substring and shrink continously until
 * the window is not longer a substring
 * We need hashmap to track every char freq
 * */
class Solution
{
  public:
    string minWindow(string s, string t)
    {
        // Base case
        if (t.length() > s.length())
        {
            return "";
        }

        if (s == t)
        {
            return s;
        }

        std::unordered_map<char, int> map_s, map_t;
        for (const auto ch : t)
        {
            map_t[ch]++;
        }

        int left{}, right{};
        int minIndex{-1}, minLen{INT_MAX};

        while (right < s.length())
        {
            map_s[s[right]]++;

            while (helper(map_s, map_t))
            {
                if (minLen > right - left + 1)
                {
                    minLen = right - left + 1;
                    minIndex = left;
                }

                // Shrink the window
                map_s[s[left]]--;
                left++;
            }
            right++;
        }

        if (minIndex == -1)
        {
            return "";
        }

        return s.substr(minIndex, minLen);
    }

    bool helper(std::unordered_map<char, int> &mp_s, std::unordered_map<char, int> &mp_t)
    {
        for (const auto &[ch, freq] : mp_t)
        {
            if (mp_s[ch] < freq)
            {
                return false;
            }
        }

        return true;
    }
};

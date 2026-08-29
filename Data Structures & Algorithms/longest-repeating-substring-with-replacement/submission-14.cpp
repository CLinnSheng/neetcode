#include <string>
#include <unordered_map>
using std::string;
/*
 * Longest repeating character replacement. Ok so we given `k` times to replace existing character
 * We can use sliding window algo but the thing how do we determine which char to replace?
 * And what is the condition of shrinking and expanding?
 * The optimal way is replacing the char to the char with the most freq in the string, so that we can minimize the
 * lenght of the string
 * So we need to always keep track of the current maximum char in the window but not string
 * IMPORTANT: Not the most freq in the `string` but instead is `window` because it is not guaranteed that it will
 * produce the longest string
 * */
class Solution
{
  public:
    int characterReplacement(string s, int k)
    {
        std::unordered_map<int, int> freq;
        int left{}, right{};
        int maxLen{};
        int maxFreq{};

        while (right < s.length())
        {
            // Insert the right
            freq[s[right]]++;
            maxFreq = std::max(maxFreq, freq[s[right]]);

            // Check whether the number of replacement is within k
            while ((right - left + 1) - maxFreq > k)
            {
                // Shrink the window
                maxFreq = std::max(maxFreq, freq[s[left]] - 1);
                freq[s[left]]--;
                left++;
            }

            maxLen = std::max(maxLen, right - left + 1);

            right++;
        }

        return maxLen;
    }
};

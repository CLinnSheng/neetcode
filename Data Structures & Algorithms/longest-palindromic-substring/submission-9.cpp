#include <string>
using std::string;

class Solution
{
  public:
    string longestPalindrome(string s)
    {
        // Finding the longest palindromic substring
        // 1 character also consider a palindromic
        // Brute force way is just simply finding all the possible substring O(n^2) then check which cost another O(n)
        // in total O(n^3)

        int len = s.length();
        // What we can do is actually scan neighbors, left and right
        // Odd Length
        // Even length will just simply scan 1 neighbor

        // handling edge case
        if (len == 1)
        {
            return s;
        }

        std::string ans{};
        int maxLen{};

        // Odd Length
        for (int i{}; i < len - 1; i++)
        {
            int left = i, right = i;
            while (left >= 0 && right < len)
            {
                if (s[left] != s[right])
                {
                    break;
                }

                if (right - left + 1 > maxLen)
                {
                    maxLen = right - left + 1;
                    ans = s.substr(left, maxLen);
                }

                left--;
                right++;
            }
        }

        // Even length
        for (int i{}; i < len - 1; i++)
        {
            int left = i, right = i + 1;
            while (left >= 0 && right < len)
            {
                if (s[left] != s[right])
                {
                    break;
                }

                if (right - left + 1 > maxLen)
                {
                    maxLen = right - left + 1;
                    ans = s.substr(left, maxLen);
                }

                left--;
                right++;
            }
        }

        return ans;
    }
};

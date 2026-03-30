#include <string>

/*
 * Given a string s, return true if the s can be a palindrome after deleting at most one character from it
 *
 * Constraint: Only lowercase letter
 * Goal: Check whether the string is palindrome or not (can delete at most one character)
 *
 * Intuitoin:
 * The brute force way will just simply try all possibel string by deleting 1 character
 * Time Complexity: O(N^2)
 * */
class Solution
{
  private:
    bool isPalindomre(const std::string &s)
    {
        int left{}, right(s.length() - 1);

        while (left < right)
        {
            if (s[left] != s[right])
                return false;

            left++;
            right--;
        }
        return true;
    }

  public:
    bool validPalindrome(std::string s)
    {
        if (isPalindomre(s))
            return true;
        for (int i{}; i < s.length(); i++)
        {
            std::string new_str = s.substr(0, i) + s.substr(i + 1);
            if (isPalindomre(new_str))
                return true;
        }
        return false;
    }
};

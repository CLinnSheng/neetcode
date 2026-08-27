#include <string>
#include <vector>
using std::string;

/*
 * Finding the length of longest common subsequence between the two strings
 *
 * Intuition:
 * We need 2 pointer where each pointer tracking 1 text
 * Ok then for each iteration, we have multiple choice
 * 1. Pointer 1
 *  a. We can skip current index
 * 2. Pointer 2
 *  a. Skip current index
 * Include this index if they are equal
 * Time Complexity: O(2^n * 2^m)
 *
 * Observation from recursive, we can see some of the subproblem have been compute multiple times
 * Why dont we cache it & reuse it if we encounter the same subproblem again in the future
 * dp[i][j] --> Longest common substring at index i in text 1 and index j at text 2
 * Time Complexity: O(m*n)
 *
 * */
class Solution
{
  public:
    int longestCommonSubsequence(string text1, string text2)
    {
        // Base Case
        if (text1 == text2)
        {
            return text1.length();
        }

        std::vector<std::vector<int>> dp(text1.length(), std::vector<int>(text2.length(), -1));
        return recursive(text1, text2, 0, 0, dp);
    }

    int recursive(const string &text1, const string &text2, int ptr1, int ptr2, std::vector<std::vector<int>> &dp)
    {
        // Base case
        if (ptr1 == text1.length() || ptr2 == text2.length())
        {
            return 0;
        }

        if (dp[ptr1][ptr2] != -1)
        {
            return dp[ptr1][ptr2];
        }

        int len{};

        // First Case: Match alphabet
        if (text1[ptr1] == text2[ptr2])
        {
            len = 1 + recursive(text1, text2, ptr1 + 1, ptr2 + 1, dp);
        }

        // Skip current index for either of the text
        len = std::max(recursive(text1, text2, ptr1 + 1, ptr2, dp), len);
        len = std::max(recursive(text1, text2, ptr1, ptr2 + 1, dp), len);

        return dp[ptr1][ptr2] = len;
    }
};

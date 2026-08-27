#include <climits>
#include <string>
#include <vector>
using std::string;

/*
 * Return the minimum number of operations to make word1 equal to word2
 *
 * At each index we can do 3 operations which is insert, delete or replace.
 * So basically this show that this is a decision tree problem.
 * Then we can solve it naively with recursive
 * Information needed, pointer on each word
 * We only do the operation when the characters dont match
 * Time Complexity: O(3^n * 3^m)
 *
 * Observation from recursive
 * If we observe we solving subproblem multiple time, why dont we cache the result and reuse it
 * when we face the same subproblem
 * dp[i][j] --> Number of operation to get the desire output from index i at word1 and index j at word2
 * Time Complexity: O(m * n)
 * */

class Solution
{
  public:
    int minDistance(string word1, string word2)
    {
        std::vector<std::vector<int>> dp(word1.length() + word2.length(),
                                         std::vector<int>(word1.length() + word2.length(), -1));
        return recursive(word1, word2, 0, 0, dp);
    }

    int recursive(const string &word1, const string &word2, int ptr1, int ptr2, std::vector<std::vector<int>> &dp)
    {

        // if ptr1 goes out of bound and ptr2 still havent reach yet then just insert the rest
        // This case happen when we keep deleting in word1
        if (ptr1 == word1.length())
        {
            return word2.length() - ptr2;
        }

        // if ptr2 goes out of bound then we just delete the rest of word we couldnt match from word1
        // This case happen when we keep inserting word at word1
        if (ptr2 == word2.length())
        {
            return word1.length() - ptr1;
        }

        if (dp[ptr1][ptr2] != -1)
        {
            return dp[ptr1][ptr2];
        }

        int operation{INT_MAX};

        // Insert at word1 at ptr1 with the character of word2 at ptr2
        operation = std::min(operation, 1 + recursive(word1, word2, ptr1, ptr2 + 1, dp));

        // Delete at word1 at ptr1
        operation = std::min(operation, 1 + recursive(word1, word2, ptr1 + 1, ptr2, dp));

        // Replace
        operation = std::min(operation, 1 + recursive(word1, word2, ptr1 + 1, ptr2 + 1, dp));
        // match
        if (word1[ptr1] == word2[ptr2])
        {
            operation = recursive(word1, word2, ptr1 + 1, ptr2 + 1, dp);
        }

        return dp[ptr1][ptr2] = operation;
    }
};

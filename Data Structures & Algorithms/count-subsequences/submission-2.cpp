#include <string>
#include <string_view>
#include <vector>
/*
 * Return the number of distinct subsequences of s which are equal to t.
 * We can solve it by recursion. And have pointer on each string. When they equal we can either proeed with it or skip
 * it
 * Time Complexity: O(2^n)
 *
 * Observation from recursive approach, some problems are solved multiple times.
 * We can cache it and reuse when face the same subproblem
 * cache[i][j] --> Number of distinct subsequences when i at s & j at t
 * Time Complexity: O(m * n)
 * */
class Solution
{
  public:
    int numDistinct(std::string s, std::string t)
    {
        // Edge Case
        if (s.length() < t.length())
        {
            return 0;
        }

        std::vector<std::vector<int>> cache(s.length(), std::vector<int>(t.length(), -1));
        return dfs(s, t, 0, 0, cache);
    }

    int dfs(std::string_view s, std::string_view t, int ptrS, int ptrT, std::vector<std::vector<int>> &cache)
    {
        if (ptrT == t.length())
        {
            return 1;
        }

        if (ptrS == s.length())
        {
            return 0;
        }

        if (cache[ptrS][ptrT] != -1)
        {
            return cache[ptrS][ptrT];
        }

        int cnt{};

        // If same moving ptrS is one of the option
        if (s[ptrS] == t[ptrT])
        {
            cnt += dfs(s, t, ptrS + 1, ptrT + 1, cache);
        }

        // Skipping it also is one of the option
        cnt += dfs(s, t, ptrS + 1, ptrT, cache);

        return cache[ptrS][ptrT] = cnt;
    }
};

#include <string>
#include <string_view>
#include <vector>
/*
 * '.' - any single character
 * '*' - zero or more of the preceding elements
 *
 * We can solve it by doing recursively, we only have different choices when we encounter '*'.
 * Otherwise the other just simple compare it or just straight match it for '.'
 * So at each index we got 2 choices when we encounter with '*' then therefor we can say that the time complexity will
 * be O(2^m+n)
 *
 * If you notice from the recursive approach, some subproblem is being solved multiple times
 * We can simply cache it and reuse.
 * since dfs(ptr_s, ptr_p) --> can we match s[ptr_s:] & p[ptr_p:]?
 * The only 2 information pass down is the pointer for both string
 * Then we can use 2d
 * dp[i][j] --> Can we match s[i:] and p[j:]?
 * */
class Solution
{
  public:
    bool isMatch(std::string s, std::string p)
    {
        std::vector<std::vector<int>> cache(s.length() + 1, std::vector<int>(p.length() + 1, -1));
        return dfs(s, p, 0, 0, cache);
    }

    bool dfs(std::string_view s, std::string_view p, int ptr_s, int ptr_p, std::vector<std::vector<int>> &cache)
    {
        if (cache[ptr_s][ptr_p] != -1)
        {
            return cache[ptr_s][ptr_p];
        }

        // Base case
        // We match finish the pattern in P
        if (ptr_p == p.length())
        {
            return cache[ptr_s][ptr_p] = ptr_s == s.length();
        }

        // Edge cases s is exhuasted but p might be contain 'a*' that still can be match because can be 0
        bool match = (ptr_s < s.length()) && (s[ptr_s] == p[ptr_p] || p[ptr_p] == '.');

        // Handle 2 Cases for '*'
        // 1. Either we make it 0
        // 2. Match it and continue with the same pattern to match more
        if (ptr_p + 1 < p.length() && p[ptr_p + 1] == '*')
        {
            return cache[ptr_s][ptr_p] = dfs(s, p, ptr_s, ptr_p + 2, cache) || (match && dfs(s, p, ptr_s + 1, ptr_p, cache));
        }

        if (match)
        {
            return cache[ptr_s][ptr_p] = dfs(s, p, ptr_s + 1, ptr_p + 1, cache);
        }

        return cache[ptr_s][ptr_p] = 0;
    }
};

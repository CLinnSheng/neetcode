#include <string>
#include <string_view>
#include <vector>
/*
 * Each move we can take from i + minJump <= j <= min(i + maxJump, n - 1)
 * The brute force way will just try to move every single possible jump in each index that we land
 * This will take O(2^n)
 * We can improve it by caching because some subproblem is solved multiple times
 * cache[i] means we can reach the final index from index i
 * */
class Solution
{
  public:
    bool canReach(std::string s, int minJump, int maxJump)
    {
        std::vector<int> cache(s.length(), -1);
        return dfs(s, 0, minJump, maxJump, cache);
    }

    int dfs(std::string_view s, int index, int minJump, int maxJump, std::vector<int> &cache)
    {
        if (index == s.length() - 1)
        {
            return cache[index] = 1;
        }

        if (cache[index] != -1)
        {
            return cache[index];
        }

        for (int i{index + minJump}; i <= std::min(index + maxJump, (int)s.length() - 1); i++)
        {
            if (s[i] == '0' && dfs(s, i, minJump, maxJump, cache))
            {
                return cache[i] = 1;
            }
        }

        if (cache[index] == -1)
        {
            cache[index] = 0;
        }

        return cache[index];
    }
};

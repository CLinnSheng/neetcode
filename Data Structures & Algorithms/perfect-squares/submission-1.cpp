#include <algorithm>
#include <climits>
#include <cmath>
#include <vector>
class Solution
{
  public:
    int numSquares(int n)
    {
        // Finding the least number of perfect square nubmers that sum up to n.
        // So at every index we can either choose it or skip it. And it can be used more than once
        // Observation from the recursive, we are doing the subproblme multiple time and thus
        // we can cache it and reuse it.
        // dp[i] =  min number of perfect square numbers sum to i

        std::vector<int> cache(n + 1, -1);
        return dfs(n, cache);
    }

    int dfs(int valLeft, std::vector<int> &cache)
    {
        // base case
        if (valLeft == 0)
        {
            return 0;
        }

        if (cache[valLeft] != -1)
        {
            return cache[valLeft];
        }

        int cnt{INT_MAX};

        for (int i{1}; i * i <= valLeft; i++)
        {
            cnt = std::min(cnt, 1 + dfs(valLeft - i * i, cache));
        }

        return cache[valLeft] = cnt;
    }
};

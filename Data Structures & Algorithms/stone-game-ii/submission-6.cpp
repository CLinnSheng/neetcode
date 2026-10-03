#include <algorithm>
#include <climits>
#include <numeric>
#include <vector>
/*
 * Find out the maximum amount of Alice will get
 *
 * Each player plays optimally. Each turn, player can take all the stones in the first x remaining piles. where  1 <= X
 * <= 2M and M=max(M,X) and set to 1 initially So the brute force way will be using recursive approach at each turn the
 * player can choose to include from 1 to 2M. So we just iterate all thoruhg it and get the maximum.
 * Time complexity: O(2^n) as at each nidex we can either choose it or skip it
 *
 * Observation from the recursive approach, we solved some subproble multiple times, we can cache it and reuse it
 * This reduce the time complexity to O(n^3)
 * As we got possible n^2 states because we got n index and n possible M values
 * Each iteration we loop through 2M so another n
 * Hence in total is O(N^3)
 * cache[i][j][k] --> Amount get in i turn at index j when M equals to k.
 *

 * */
class Solution
{
  public:
    int stoneGameII(std::vector<int> &piles)
    {
        int n = piles.size();

        std::vector<std::vector<std::vector<int>>> cache(2,
                                                         std::vector<std::vector<int>>(n, std::vector<int>(n + 1, -1)));
        return dfs(piles, 1, 0, 1, cache);
    }

    /// Find how many stones Alice get from index `index`
    int dfs(const std::vector<int> &piles, int aliceTurn, int index, int M,
            std::vector<std::vector<std::vector<int>>> &cache)
    {
        // Base Case
        if (index == piles.size())
        {
            return 0;
        }

        if (cache[aliceTurn][index][M] != -1)
        {
            return cache[aliceTurn][index][M];
        }

        int ttl{};
        // Each player plays optimally so Alice will try to maximize and Bob will try to minimize the amount Alice can
        // get
        int result = aliceTurn ? 0 : INT_MAX;

        for (int X{1}; X <= 2 * M; X++)
        {
            // Pruning
            if (index + X > piles.size())
            {
                break;
            }

            ttl += piles[index + X - 1];

            if (aliceTurn)
            {
                result = std::max(result, ttl + dfs(piles, 0, index + X, std::max(X, M), cache));
            }
            else
            {
                // Bob turn try to minimize the return from Alice
                result = std::min(result, dfs(piles, 1, index + X, std::max(X, M), cache));
            }
        }

        return cache[aliceTurn][index][M] = result;
    }
};

#include <algorithm>
#include <cmath>
#include <vector>
class Solution
{
  public:
    int integerBreak(int n)
    {
        // Break into sum of k positive integers where k  must be at least 2 and maximize the product of those integers
        // Just recursive break the n and at each point we can either skip or include it
        // Observation from the recursive approach, some subproblem is solved multiple times
        // We can cache it and reuse it
        // cache[i] simply means the maximum product for value i
        // Time Complexity:
        // 1. Recursive Approach: n^n
        // 2. DP: O(n^2) each n loop n times

        std::vector<int> cache(n + 1, -1);
        return dfs(n, cache);
    }

    int dfs(int n, std::vector<int>& cache)
    {
        if (n == 1)
        {
            return 1;
        }

        if (cache[n] != -1)
        {
            return cache[n];
        }

        int maxProduct{};
        for (int i{1}; i < n; i++)
        {
            maxProduct = std::max(maxProduct, i * std::max(n - i, dfs(n - i, cache)));
        }

        return cache[n] = maxProduct;
    }
};

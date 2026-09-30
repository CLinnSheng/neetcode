#include <numeric>
#include <vector>
/*
 * Find out whether alice will win the game or not
 *
 * Each player plays optimally. Each turn player will either pick from the front or the end.
 * Being greedy which is always pick the largest at current step doesnt guarantee to win in the end.
 * So we can try out all possible path. So instead of alice and bob takes turn, we can actually just stimulate Alice.
 * And then after thaat just comapre AliceSum with TTL - AliceSum
 * Time Complexity: O(2^n) As each index we can either include it or skip for Alice
 *
 * Observation from recursive approach
 * Some subprolbem are solved multiple times, we can reuse it by caching it
 * cache[i][j] --> Maximum Sum of Alice at index i & j
 * Time Complexity: O(n^2 )
 * */
class Solution
{
  public:
    bool stoneGame(std::vector<int> &piles)
    {
        int ttlSum = std::accumulate(piles.begin(), piles.end(), 0);
        std::vector<std::vector<int>> cache(piles.size(), std::vector<int>(piles.size(), -1));

        int AliceSum = dfs(piles, 0, piles.size() - 1, cache);

        return AliceSum > (ttlSum - AliceSum);
    }

    int dfs(const std::vector<int> &piles, int left, int right, std::vector<std::vector<int>> &cache)
    {
        if (left >= right)
        {
            return 0;
        }

        if (cache[left][right] != -1)
        {
            return cache[left][right];
        }

        // Alice Turn is always even size
        bool AliceTurn = (right - left + 1) % 2 == 0;

        // 2 choices
        // Front and end and only consider it if is alice turn
        int front = AliceTurn ? piles[left] : 0;
        int back = AliceTurn ? piles[right] : 0;

        int firstChoice = front + dfs(piles, left + 1, right, cache);
        int secondChoice = back + dfs(piles, left, right - 1, cache);

        return cache[left][right] = std::max(firstChoice, secondChoice);
    }
};

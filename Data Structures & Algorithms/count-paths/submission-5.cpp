/*
 * Goal: Find the number of possible unqiue path that can be taken from the start to the end
 * We can only move down or to the right
 * Naively, we can search through recursive
 *
 * Observation from recursive, we doing repetitive work at some subproblem. Since we already solve it at that cell, why
 * dont reuse it? We can use caching dp[i][j] simply means the number of path to the END at (i, j)
 * Time Complexity: O(n^2)
 * Space Complexity: O(n^2)
 * */
#include <utility>
#include <vector>
class Solution
{
    using Point = std::pair<int, int>;

  public:
    int uniquePaths(int m, int n)
    {
        const Point START{0, 0}, END{m - 1, n - 1};
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, -1));

        return recursive(START, END, m, n, {0, 0}, dp);
    }

    int recursive(const Point &START, const Point &END, int rows, int cols, Point currCell,
                  std::vector<std::vector<int>> &dp)
    {
        // Base Case reaching the target end cell
        if (currCell == END)
        {
            // Consider a path
            return 1;
        }

        if (dp[currCell.first][currCell.second] != -1)
        {
            return dp[currCell.first][currCell.second];
        }

        int cnt{};

        // Trying both path
        // 1. Moving to the right
        int col = currCell.second + 1;
        if (col < cols)
        {
            cnt += recursive(START, END, rows, cols, {currCell.first, col}, dp);
        }

        // 2. Moving to the down
        int row = currCell.first + 1;
        if (row < rows)
        {
            cnt += recursive(START, END, rows, cols, {row, currCell.second}, dp);
        }

        return dp[currCell.first][currCell.second] = cnt;
    }
};

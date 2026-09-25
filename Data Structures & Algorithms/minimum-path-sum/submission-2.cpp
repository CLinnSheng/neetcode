#include <climits>
#include <vector>
using std::vector;

class Solution
{
  public:
    int minPathSum(vector<vector<int>> &grid)
    {
        // Can use recusrive method where at each index we choose the min from either going down or right
        // Observation from the recursive approach
        // Subproblem is being sovle multiple times, then we can cache it and reuse
        // Time Complexity: O(2^ (m+n)) -> O(n^2) as each cell we have 2 choices.
        vector<vector<int>> cache(grid.size(), vector<int>(grid[0].size(), -1));
        return dfs(grid, 0, 0, cache);
    }

    int dfs(vector<vector<int>> &grid, int row, int col, vector<vector<int>> &cache)
    {
        // Check Boundary
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size())
        {
            return INT_MAX;
        }

        if (cache[row][col] != -1)
        {
            return cache[row][col];
        }

        if (row == grid.size() - 1 && col == grid[0].size() - 1)
        {
            return grid[row][col];
        }

        return cache[row][col] =
                   grid[row][col] + std::min(dfs(grid, row + 1, col, cache), dfs(grid, row, col + 1, cache));
    }
};

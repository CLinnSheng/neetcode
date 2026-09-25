#include <vector>
using std::vector;

class Solution
{
  public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        // Can use recursive at each step we can either go down or right, so just sum it up
        // From the recursive approach, we can see some subprolem is solved multiple times
        vector<vector<int>> cache(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));
        return dfs(obstacleGrid, 0, 0, cache);
    }

    int dfs(vector<vector<int>> &obstacleGrid, int row, int col, vector<vector<int>> &cache)
    {
        // Check Boundary
        if (row < 0 || col < 0 || row >= obstacleGrid.size() || col >= obstacleGrid[0].size())
        {
            return 0;
        }

        if (cache[row][col] != -1)
        {
            return cache[row][col];
        }

        if (obstacleGrid[row][col])
        {
            return 0;
        }

        if (row == obstacleGrid.size() - 1 && col == obstacleGrid[0].size() - 1)
        {
            return 1;
        }

        return cache[row][col] = dfs(obstacleGrid, row + 1, col, cache) + dfs(obstacleGrid, row, col + 1, cache);
    }
};

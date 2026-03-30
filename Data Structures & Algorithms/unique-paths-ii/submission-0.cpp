#include <vector>
/*
 * The robot tries to move to bottom right. And the robot can only move either down or right at any point in time
 * We can only take path there dont get into any square have obstacle
 * Goal: Return the number of possible unique paths that the robot can reach the bottom right corner
 *
 *
 * Intuition:
 * Is about the same as unique_path I. Ok so we basically at every cell we can either moves 2 way either down or right.
 * So we can just recursively get the number of paths from moving down and right. Now we just need another layer of
 * checking whether the cell is legit or not.
 * Time Complexity: O(N^N)
 *
 *  We can improve it by using caching
 * */
class Solution
{

  private:
    int dfs_caching(std::vector<std::vector<int>> &obstacleGrid, const int ROWS, const int COLS, const int row,
                    const int col, std::vector<std::vector<int>> &caching)
    {
        // Check whether is it a legit grid or not first
        if (row < 0 || row >= ROWS || col < 0 || col >= COLS || obstacleGrid[row][col])
            return 0;

        if (row == ROWS - 1 && col == COLS - 1)
            return 1;

        if (caching[row][col] != -1)
            return caching[row][col];

        return caching[row][col] = dfs_caching(obstacleGrid, ROWS, COLS, row + 1, col, caching) +
                                   dfs_caching(obstacleGrid, ROWS, COLS, row, col + 1, caching);
    }

  public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>> &obstacleGrid)
    {
        int ROWS(obstacleGrid.size()), COLS(obstacleGrid[0].size());
        std::vector<std::vector<int>> caching(ROWS, std::vector<int>(COLS, -1));
        return dfs_caching(obstacleGrid, ROWS, COLS, 0, 0, caching);
    }
};

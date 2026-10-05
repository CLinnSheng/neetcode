#include <algorithm>
#include <utility>
#include <vector>
using std::vector;

/*
 * Find the length of the longest strictly increasing path with matrix
 * Brute force way will jsut simply try all 4 possible direction and take the path that is the longest and increasing
 * Have a visited set to prevent looping
 * Time Complexity: O(m*n * 4^(m*n)) as at each cell we got 4 choices and we will be iterating thourgh all the cell, and
 * start to iterate each cell as the first cell
 *
 * From the recursive approach, we can see there is some subproblem get solved multiple times
 * we can jsut cache it and reuse it so the time complexity can cut down to O(m*n)
 * */
class Solution
{
  public:
    const vector<std::pair<int, int>> DIRECTIONS{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        int ROWS = matrix.size(), COLS = matrix[0].size();
        vector<vector<int>> cache(ROWS, vector<int>(COLS, -1));
        int ans = 0;

        for (int r{}; r < ROWS; r++)
        {
            for (int c{}; c < COLS; c++)
            {
                vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));
                ans = std::max(ans, dfs(matrix, visited, ROWS, COLS, r, c, cache));
            }
        }

        return ans;
    }

    int dfs(vector<vector<int>> &matrix, vector<vector<bool>> &visited, const int ROWS, const int COLS, int row,
            int col, vector<vector<int>> &cache)
    {
        if (visited[row][col])
        {
            return 0;
        }

        if (cache[row][col] != -1)
        {
            return cache[row][col];
        }

        int maxPath{1};
        visited[row][col] = true;

        for (const auto &direction : DIRECTIONS)
        {
            int new_row = row + direction.first;
            int new_col = col + direction.second;

            if (new_row < 0 || new_col < 0 || new_row >= ROWS || new_col >= COLS ||
                matrix[row][col] >= matrix[new_row][new_col])
            {
                continue;
            }

            maxPath = std::max(maxPath, 1 + dfs(matrix, visited, ROWS, COLS, new_row, new_col, cache));
        }

        visited[row][col] = false;

        return cache[row][col] = maxPath;
    }
};

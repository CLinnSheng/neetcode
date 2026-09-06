#include <utility>
#include <vector>
using std::vector;
/*
 * Use dfs and mark visited cell
 * */
class Solution
{
    int ROWS, COLS;

  public:
    const vector<std::pair<int, int>> DIRECTIONS{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int numIslands(vector<vector<char>> &grid)
    {
        int cnt{};
        this->ROWS = grid.size();
        this->COLS = grid[0].size();

        for (int row{}; row < grid.size(); row++)
        {
            for (int col{}; col < grid[row].size(); col++)
            {
                if (grid[row][col] == '1')
                {
                    dfs(grid, row, col);
                    cnt++;
                }
            }
        }

        return cnt;
    }

    void dfs(vector<vector<char>> &grid, int row, int col)
    {
        // Mark visited
        grid[row][col] = '0';

        for (const auto direction : DIRECTIONS)
        {
            int new_row = row + direction.first;
            int new_col = col + direction.second;

            if (new_row < 0 || new_col < 0 || new_row >= ROWS || new_col >= COLS || grid[new_row][new_col] == '0')
            {
                continue;
            }

            dfs(grid, new_row, new_col);
        }
    }
};

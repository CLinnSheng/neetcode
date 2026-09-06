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
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int maxArea{};
        this->ROWS = grid.size();
        this->COLS = grid[0].size();

        for (int row{}; row < grid.size(); row++)
        {
            for (int col{}; col < grid[row].size(); col++)
            {
                if (grid[row][col] == 1)
                {
                    maxArea = std::max(maxArea, dfs(grid, row, col));
                }
            }
        }

        return maxArea;
    }

    int dfs(vector<vector<int>> &grid, int row, int col)
    {
        // Mark visited
        grid[row][col] = 0;

        int area{1};

        for (const auto direction : DIRECTIONS)
        {
            int new_row = row + direction.first;
            int new_col = col + direction.second;

            if (new_row < 0 || new_col < 0 || new_row >= ROWS || new_col >= COLS || grid[new_row][new_col] == 0)
            {
                continue;
            }

            area += dfs(grid, new_row, new_col);
        }

        return area;
    }
};

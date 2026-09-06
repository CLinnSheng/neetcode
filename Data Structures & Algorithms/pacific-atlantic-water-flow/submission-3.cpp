#include <utility>
#include <vector>
using std::vector;
/*
 * Fidning all the cell that flow into both ocean
 * Instead of finding the cell that go into the ocean why not we do it in the reverse way which is much more simplier
 * and quickier beacuse it has to go through to border in order to get to the ocean, just start dfs from there
 * */
class Solution
{
  public:
    const vector<std::pair<int, int>> DIRECTIONS{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int ROWS, COLS;
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        ROWS = heights.size(), COLS = heights[0].size();

        vector<vector<bool>> pacific(ROWS, vector<bool>(COLS, false)), atlantic(ROWS, vector<bool>(COLS, false));

        for (int row{}; row < ROWS; row++)
        {
            dfs(heights, pacific, row, 0);
            dfs(heights, atlantic, row, COLS - 1);
        }

        for (int col{}; col < COLS; col++)
        {
            dfs(heights, pacific, 0, col);
            dfs(heights, atlantic, ROWS - 1, col);
        }

        vector<vector<int>> ans;
        for (int row{}; row < ROWS; row++)
        {
            for (int col{}; col < COLS; col++)
            {
                if (pacific[row][col] && atlantic[row][col])
                {
                    ans.push_back({row, col});
                }
            }
        }

        return ans;
    }

    void dfs(const vector<vector<int>> &heights, vector<vector<bool>> &visited, int row, int col)
    {
        // Mark visited
        visited[row][col] = true;

        for (const auto direction : DIRECTIONS)
        {
            int new_row = row + direction.first;
            int new_col = col + direction.second;

            if (new_row < 0 || new_col < 0 || new_row >= ROWS || new_col >= COLS || visited[new_row][new_col] ||
                heights[row][col] > heights[new_row][new_col])
            {
                continue;
            }

            dfs(heights, visited, new_row, new_col);
        }
    }
};

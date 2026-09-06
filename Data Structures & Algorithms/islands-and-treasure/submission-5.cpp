#include <deque>
#include <vector>
using std::vector;
/*
 * Fill each land cell with the distance to its nearest treaure chest.
 * Modify the grid in place.
 * Instead of starting from land cell to the treasure, we can actually doing the opposite which is much more eaiser.
 * And then also prevent dead cycle, we only visit the land if we found shorter route
 * DFS/BFS? BFS will be much more simpler to implement
 * */
class Solution
{
  public:
    const int INF = 2147483647;
    const vector<std::pair<int, int>> DIRECTIONS{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void islandsAndTreasure(vector<vector<int>> &grid)
    {
        std::deque<std::pair<int, int>> queue;

        for (int r{}; r < grid.size(); r++)
        {
            for (int c{}; c < grid[0].size(); c++)
            {
                if (grid[r][c] == 0)
                {
                    queue.push_back({r, c});
                }
            }
        }

        int step{1};

        while (!queue.empty())
        {
            int currSize = queue.size();

            while (currSize)
            {
                auto curr = queue.front();
                int currRow = curr.first, currCol = curr.second;
                queue.pop_front();

                for (const auto direction : DIRECTIONS)
                {
                    int new_row = currRow + direction.first;
                    int new_col = currCol + direction.second;

                    if (new_row < 0 || new_col < 0 || new_row >= grid.size() || new_col >= grid[0].size() ||
                        grid[new_row][new_col] != INF)
                    {
                        continue;
                    }

                    grid[new_row][new_col] = step;
                    queue.push_back({new_row, new_col});
                }

                currSize--;
            }

            step++;
        }
    }
};

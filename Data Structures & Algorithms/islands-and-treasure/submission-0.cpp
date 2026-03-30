#include <cstdint>
class Solution {
public:
    const std::vector<std::pair<int, int>> DIRECTIONS = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  void islandsAndTreasure(std::vector<std::vector<int>> &grid) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    if (grid.empty()) return;

    int n_row = grid.size(), n_col = grid[0].size();
    std::deque<std::pair<int, int>> queue;

    for (int row = 0; row < n_row; row++)
        for (int col = 0; col < n_col; col++)
            if (grid[row][col] == 0)
                queue.emplace_back(row, col);

    while (!queue.empty()) {
        const auto& coordinate = queue.front();
        queue.pop_front();
        int y = coordinate.first;
        int x = coordinate.second;

        for (const auto& [_row, _col] : DIRECTIONS) {
            auto new_row = y + _row;
            auto new_col = x + _col;

            if (new_row < 0 || new_col < 0 || new_col >= n_col || new_row >= n_row || grid[new_row][new_col] != INT_MAX)
                continue;

            grid[new_row][new_col] = std::min(grid[new_row][new_col],  grid[y][x] + 1);
            queue.emplace_back(new_row, new_col);
        }

    }
  }

};

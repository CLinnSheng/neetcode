#include <climits>
#include <cstdlib>
#include <queue>
#include <utility>
#include <vector>
/*
 * Goal: Find the minimum effort  to ravel from top left to bottom right
 * Effort: Maximum absolute difference in heights
 *
 * Intuition: This is a graph problem and we want to minimize the effort.
 * So everytime when choosing which cell to travel, we always prefer that has
 * the minimum absolute differences
 * So we basically just dfs and backtrack
 * */

struct Comparator {
  bool operator()(const std::pair<std::pair<int, int>, int> &A,
                  const std::pair<std::pair<int, int>, int> &B) {

    return A.second > B.second;
  }
};

class Solution {
public:
  int minimumEffortPath(std::vector<std::vector<int>> &heights) {
    int ROWS = heights.size(), COLS = heights[0].size();
    const std::pair<int, int> START = {0, 0}, END = {ROWS - 1, COLS - 1};
    const std::vector<std::pair<int, int>> DIRECTIONS = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    std::vector<std::vector<int>> dist(ROWS, std::vector<int>(COLS, INT_MAX));

    std::priority_queue<std::pair<std::pair<int, int>, int>,
                        std::vector<std::pair<std::pair<int, int>, int>>,
                        Comparator>
        queue;
    dist[0][0] = 0;
    queue.emplace(START, 0);

    while (!queue.empty()) {
      auto top = queue.top();
      queue.pop();

      if (top.first == END) {
        return top.second;
      }

      int row = top.first.first;
      int col = top.first.second;

      // Travel all possible path
      for (const auto &[_row, _col] : DIRECTIONS) {
        int new_row = _row + row;
        int new_col = _col + col;

        // Boundary Checking
        if (new_row < 0 || new_col < 0 || new_row >= ROWS || new_col >= COLS) {
          continue;
        }

        int diff = std::abs(heights[row][col] - heights[new_row][new_col]);
        int effort = std::max(diff, top.second);

        // Another checking on should we visit the cell or not
        if (effort >= dist[new_row][new_col]) {
          continue;
        }

        queue.push({{new_row, new_col}, effort});
        dist[new_row][new_col] = effort;
      }
    }

    return -1;
  }
};

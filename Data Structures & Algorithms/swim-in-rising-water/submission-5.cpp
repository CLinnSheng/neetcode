/*
Rain starts to fall at time, t = 0. At time t, the water level accross the
entire grid is t
Allow can swim to another grid if the original elevation of both squares is less
than or equal to the water level at time t. Goal: Find the minimum amount of
time to reach (n - 1, n - 1)  from (0, 0)

Intuition:
Moving across cell dont takes time.
We can only move from one cell to its adjacent if and only if the time is
greater than or equal to the adjacent's cell eleveation. So what we can do over
here is finding the shortest path from the start to the end and then just simply
return the maximum elevation for that path We can use dijkstra algorithm to find
the shortest path with the least time
One important thing is we dont always start from 1
Time Complexity: O(N^2logN^2) --> O(N^2logN)
*/
#include <climits>
#include <queue>
#include <utility>
#include <vector>

struct Comparator {
  bool operator()(const std::pair<std::pair<int, int>, int> &A,
                  const std::pair<std::pair<int, int>, int> &B) {
    return A.second > B.second;
  }
};
class Solution {
public:
  int swimInWater(std::vector<std::vector<int>> &grid) {
    const std::vector<std::pair<int, int>> DIRECTIONS{
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    const int ROWS = grid.size(), COLS = grid[0].size();
    std::priority_queue<std::pair<std::pair<int, int>, int>,
                        std::vector<std::pair<std::pair<int, int>, int>>,
                        Comparator>
        minHeap;
    std::vector<std::vector<int>> times(ROWS, std::vector<int>(COLS, INT_MAX));
    times[0][0] = grid[0][0];

    minHeap.push({{0, 0}, grid[0][0]});

    while (!minHeap.empty()) {
      auto top = minHeap.top();
      auto cell = top.first;
      auto currTime = top.second;
      minHeap.pop();

      if (cell.first == ROWS - 1 && cell.second == COLS - 1) {
        return currTime;
      }

      for (const auto &direction : DIRECTIONS) {
        int new_row = cell.first + direction.first;
        int new_col = cell.second + direction.second;

        if (new_row < 0 || new_col < 0 || new_row >= ROWS || new_col >= COLS) {
          continue;
        }

        int new_time = std::max(currTime, grid[new_row][new_col]);

        // Make decision on travel to this cell or not.
        // Travel to it if the time taken is lesser
        if (new_time < times[new_row][new_col]) {
          times[new_row][new_col] = new_time;
          minHeap.push({{new_row, new_col}, new_time});
        }
      }
    }

    return -1;
  }
};

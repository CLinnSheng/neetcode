#include <cstdlib>
#include <queue>
#include <utility>
#include <vector>

/*
 * Goal: Find the minimum cost to connect all the points
 *
 * Intuition: Gives a list of points but doesnt comes with the edges
 * Means that we can connect how ever we want with all the points
 * So we can use minHeap to actaully choose the point to connect based on the
 * euclidean distance stored
 * */

struct Comparator {
  bool operator()(const std::pair<int, int> &A, const std::pair<int, int> &B) {
    return A.second > B.second;
  }
};

class Solution {
private:
  int computeDistance(const std::vector<int> &A, const std::vector<int> &B) {
    return std::abs(A[0] - B[0]) + std::abs(A[1] - B[1]);
  }

public:
  int minCostConnectPoints(std::vector<std::vector<int>> &points) {
    int N = points.size();
    std::vector<bool> visited(N, false);

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        Comparator>
        minHeap;
    minHeap.push({0, 0});
    int cost{};

    while (!minHeap.empty()) {
      auto curr = minHeap.top();
      minHeap.pop();

      if (visited[curr.first]) {
        continue;
      }

      int point = curr.first;
      int curCost = curr.second;

      cost += curCost;
      visited[point] = true;

      // Push all the possible edges
      for (int i{}; i < N; i++) {
        if (i == point) {
          continue;
        }

        int distance = computeDistance(points[point], points[i]);
        minHeap.push({i, distance});
      }
    }

    return cost;
  }
};

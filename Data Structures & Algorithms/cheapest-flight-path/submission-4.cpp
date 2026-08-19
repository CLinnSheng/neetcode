/*
Goal: Find the cheapest price from src to dest within k stops

Intuition: This is a graph problem since it mention about finding the `cheapest`
We can use dijkstra algorithm
So information we need to pass down is (current_node, step_taken, cost)
*/

#include <array>
#include <climits>
#include <queue>
#include <utility>
#include <vector>
struct Comparator {
  bool operator()(const std::array<int, 3> &A, const std::array<int, 3> &B) {
    return A[2] > B[2];
  };
};
class Solution {
public:
  int findCheapestPrice(int n, std::vector<std::vector<int>> &flights, int src,
                        int dst, int k) {
    // Building the adjList
    std::vector<std::vector<std::pair<int, int>>> adjList(
        n, std::vector<std::pair<int, int>>());
    for (const auto &flight : flights) {
      adjList[flight[0]].push_back({flight[1], flight[2]});
    }

    // Cheapest  cost doesnt always end up with the best ans
    // we have to consider the step taken as well
    std::vector<std::vector<int>> dists(n, std::vector<int>(k + 5, INT_MAX));
    dists[src][0] = 0;
    std::priority_queue<std::array<int, 3>, std::vector<std::array<int, 3>>,
                        Comparator>
        minHeap;
    // Beacuse src and destination doesnt count
    minHeap.push({src, -1, 0});

    while (!minHeap.empty()) {
      auto [currNode, stepTaken, currCost] = minHeap.top();
      minHeap.pop();

      if (currNode == dst) {
        return currCost;
      }
      if (stepTaken == k || dists[currNode][stepTaken + 1] < currCost) {
        continue;
      }

      // Exploring all the neigh
      for (const auto &[neighNode, neighCost] : adjList[currNode]) {
        int newCost = neighCost + currCost;
        int newStep = stepTaken + 1;
        if (dists[neighNode][newStep + 1] > newCost) {
          minHeap.push({neighNode, newStep, newCost});
          dists[neighNode][newStep + 1] = newCost;
        }
      }
    }
    return -1;
  }
};

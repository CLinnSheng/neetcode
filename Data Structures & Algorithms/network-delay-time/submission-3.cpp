#include <climits>
#include <queue>
#include <utility>
#include <vector>

/*
 * Directed graph
 * Goal: Find the minimum time it takes for all of the n nodes to receive the
 * signal from node k
 *
 * Intuition:
 * This is a graph problem and we can use dijkstra algorithm to always choose
 * the node with the least time to expand
 * */

struct Comparator {
  bool operator()(const std::pair<int, int> &A, const std::pair<int, int> &B) {
    return A.second > B.second;
  }
};

class Solution {
public:
  int networkDelayTime(std::vector<std::vector<int>> &times, int n, int k) {
    // Build the adj list
    std::vector<std::vector<std::pair<int, int>>> adjList(
        n + 1, std::vector<std::pair<int, int>>());
    for (const auto &time : times) {
      adjList[time[0]].push_back({time[1], time[2]});
    }
    std::vector<int> dist(n + 1, INT_MAX);
    dist[k] = 0;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        Comparator>
        minHeap;
    minHeap.push({k, 0});

    while (!minHeap.empty()) {
      auto top = minHeap.top();
      minHeap.pop();
      int currNode = top.first;

      for (const auto neigh : adjList[currNode]) {
        int neighNode = neigh.first;
        int timeTaken = top.second + neigh.second;

        if (timeTaken >= dist[neighNode]) {
          continue;
        }

        dist[neighNode] = timeTaken;
        minHeap.push({neighNode, timeTaken});
      }
    }

    int ans = {-1};
    for (int i{1}; i <= n; i++) {
      ans = std::max(ans, dist[i]);
    }

    return ans == INT_MAX ? -1 : ans;
  }
};

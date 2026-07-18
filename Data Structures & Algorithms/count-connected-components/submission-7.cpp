#include <unordered_set>
#include <vector>
/*
 * Find the number of count components, we can use union find algorithm to
 * construct each graph Then after that only find out the number of each
 * connected component
 * Time Complexity: O(1)
 * */
class Solution {

  // Time Complexity of Path Compression is O(1)
  // because the tree almost never grow talls and stay flat
  int findParent(int currNode, std::vector<int> &parents) {
    // Path Compression
    if (parents[currNode] != currNode) {
      parents[currNode] = findParent(parents[parents[currNode]], parents);
    }

    return parents[currNode];
  }

  void unionFind(int node_1, int node_2, std::vector<int> &ranks,
                 std::vector<int> &parents) {
    int parent_1 = findParent(node_1, parents);
    int parent_2 = findParent(node_2, parents);

    // Same parents mean they are connected
    if (parent_1 == parent_2) {
      return;
    }

    // Otherwise merge it and update the parents & ranks
    if (ranks[parent_1] > ranks[parent_2]) {
      parents[parent_2] = parent_1;
      ranks[parent_1] += ranks[parent_2];
    } else {
      parents[parent_1] = parent_2;
      ranks[parent_2] += ranks[parent_1];
    }
  }

public:
  int countComponents(int n, std::vector<std::vector<int>> &edges) {
    std::vector<int> parents(n, 0), ranks(n, 1);
    for (int i{}; i < n; i++) {
      parents[i] = i;
    }

    // Connect all the edges
    for (const auto &edge : edges) {
      unionFind(edge[0], edge[1], ranks, parents);
    }

    // Make all the node in the parents array point to their root node
    for (int i{}; i < n; i++) {
      findParent(i, parents);
    }

    // Number of connected graphs simply means number of distinct parent node
    std::unordered_set<int> ans(parents.begin(), parents.end());

    return ans.size();
  }
};

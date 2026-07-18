#include <vector>
/*
 * Initially no cycles and n edges
 * Find out the edges that can be remove and still be a connected non-cyclical
 * graph So we need to determine which edge causing the graph to have a cycle.
 * We can use Union Find Algortihm to construct the graph and find out the edge
 * that causes cycle because when constructing the graph we always check whether
 * are they connected or not, if they are connected and with the same parent
 * then that's means the edge we gonna add wil cause a cycle
 * IMPORTANT OBSERVATION IS ONLY RETURN THE LAST EDGE IN THE ARRAY THAT CAUSING
 * IT so UnionFind Algorithm truly statisfy this
 * */
class Solution {
private:
  int findParent(int node, std::vector<int> &parents) {
    if (node != parents[node]) {
      parents[node] = findParent(parents[parents[node]], parents);
    }

    return parents[node];
  }

  bool unionFind(int node_1, int node_2, std::vector<int> &ranks,
                 std::vector<int> &parents) {
    int parent_1 = findParent(node_1, parents);
    int parent_2 = findParent(node_2, parents);

    // Find the edge that causing a cycle
    if (parent_1 == parent_2) {
      return true;
    }

    if (ranks[parent_1] > ranks[parent_2]) {
      parents[parent_2] = parent_1;
      ranks[parent_1] += ranks[parent_2];
    } else {
      parents[parent_1] = parent_2;
      ranks[parent_2] += ranks[parent_1];
    }

    return false;
  }

public:
  std::vector<int>
  findRedundantConnection(std::vector<std::vector<int>> &edges) {
    int n = edges.size();
    std::vector<int> ranks(n + 1, 1), parents(n + 1);
    for (int i{}; i < n; i++) {
      parents[i] = i;
    }

    for (const auto &edge : edges) {
      if (unionFind(edge[0], edge[1], ranks, parents)) {
        return edge;
      }
    }

    return {};
  }
};

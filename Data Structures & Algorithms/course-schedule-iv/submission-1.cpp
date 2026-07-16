#include <functional>
#include <vector>
/*
 * prerequisites[i] = [ai, bi] indicates that you must take course ai first if
 * you want to take course bi
 * Check each query in the array whether query = [u,
 * j] u is a prerequisite course of j or not. Ok so the first thing is we need
 * to build the graph connecting the nodes with prerequisite Then check each
 * query from it
 *
 * 1. Brute force way will just simply run through the prerequisites for each
 * query
 * Time Complexity: O( N * (V + E))
 *
 * 2. Observe from brute force, we kind of overlapping on the doing the same
 * thing when searching through the graph What we can do is caching the courses
 * that we already confirmed is the prerequisites from previous query
 * Time Complexity: O( N * (V + E)) but in term of averagely will be perform
 * better than the brute force
 * */
class Solution {
public:
  std::vector<bool>
  checkIfPrerequisite(int numCourses,
                      std::vector<std::vector<int>> &prerequisites,
                      std::vector<std::vector<int>> &queries) {
    std::vector<std::vector<int>> adjList(numCourses, std::vector<int>());
    for (const auto &prerequisite : prerequisites) {
      adjList[prerequisite[0]].push_back(prerequisite[1]);
    }
    std::vector<std::vector<int>> caching(numCourses,
                                          std::vector<int>(numCourses, -1));

    std::vector<bool> ans;

    std::function<bool(const int, const int)> dfs = [&](const int currNode,
                                                        const int targetNode) {
      if (caching[currNode][targetNode] != -1) {
        return caching[currNode][targetNode] == 1;
      }

      if (currNode == targetNode) {
        return true;
      }

      for (const int neigh : adjList[currNode]) {
        if (dfs(neigh, targetNode)) {
          caching[currNode][targetNode] = 1;
          return true;
        }
      }

      caching[currNode][targetNode] = 0;
      return false;
    };

    for (const auto &query : queries) {
      ans.push_back(dfs(query[0], query[1]));
    }
    return ans;
  }
};

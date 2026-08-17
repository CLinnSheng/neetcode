#include <algorithm>
#include <functional>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

/*
 * Words: Sorted lexicographically
 * Goal: Derive the order of letters in this new language and return the new
 * alien langauge
 *
 * Treat each letter as a node. Then the edge will just simply be the order.
 * Eg A -> B means A comes before B.
 * We can simply build the adjList & DFS to find the path. If got cycle means
 * got dependency issues and thus invalid
 * IMPORTANT OBSERVATION: We can have more than 1 answer, because the condition
 * we have to statisfied is just those with edges And those isolated char can be
 * at any position as long as those have edges statisfy the orders
 *
 * Time Complexity:
 * C - All characters
 * Building Nodes - O(C)
 * Building Edges - O(C)
 * DFS - O(V + E)
 * Reverse - O(V)
 * Hence O(C + V + E)
 *
 * */
class Solution {
public:
  std::string foreignDictionary(std::vector<std::string> &words) {
    // Building the AdjList
    std::unordered_map<char, std::unordered_set<char>> adjList;
    for (const auto &word : words) {
      for (const auto ch : word) {
        adjList[ch];
      }
    }

    for (int i{}; i < words.size() - 1; i++) {
      std::string &str1 = words[i], &str2 = words[i + 1];
      int minLen = std::min(str1.length(), str2.length());

      // Check whether the order is valid or not
      // First String is Longer and has same prefix
      if (str1.length() > str2.length() &&
          str1.substr(0, minLen) == str2.substr(0, minLen)) {
        return "";
      }

      // Find the first diff character
      for (int j{}; j < minLen; j++) {
        if (str1[j] != str2[j]) {
          adjList[str1[j]].insert(str2[j]);
          break;
        }
      }
    }

    // 3 States
    // Unvisited which is not in map
    // Visiting (In current path) true
    // Visited (Done) false
    std::unordered_map<char, bool> visited;
    std::string ans;

    std::function<bool(const char)> dfs = [&](const char ch) {
      // If visited before, then check whether is it in current path or not
      if (visited.find(ch) != visited.end()) {
        return visited[ch];
      }

      // Visiting
      visited[ch] = true;
      for (const auto neigh : adjList[ch]) {
        if (dfs(neigh)) {
          return true;
        }
      }

      // Done visiting all the nodes in the path
      // mark false
      visited[ch] = false;
      ans.push_back(ch);
      return false;
    };

    for (const auto [word, _] : adjList) {
      if (dfs(word)) {
        return "";
      }
    }

    std::reverse(ans.begin(), ans.end());
    return ans;
  }
};

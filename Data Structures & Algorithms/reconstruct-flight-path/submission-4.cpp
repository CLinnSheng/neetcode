#include <algorithm>
#include <deque>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

/*
 * Given list of source and destination and reconstruct the itinerary
 *
 * Intuition:
 * Must be start from "JFK" and each ticket must be use exactly once
 * Final output must be in lexicographically order
 * First thought is using dfs but is not efficient and what if we try a node
 * that end up in a dead end?
 * What if we do it in a reverse manner? instead of visiting the first airport
 * why not we try from the back first. So we definitely will visit all airport
 * in the end
 * */
class Solution {
public:
  std::vector<std::string>
  findItinerary(std::vector<std::vector<std::string>> &tickets) {
    // Build the adjlist
    std::unordered_map<std::string, std::deque<std::string>> adjList;
    for (const auto &ticket : tickets) {
      adjList[ticket[0]].push_back(ticket[1]);
    }

    // Sort it
    for (auto &[src, destinations] : adjList) {
      std::sort(destinations.begin(), destinations.end());
    }

    std::vector<std::string> ans;

    std::function<void(const std::string &)> dfs =
        [&](const std::string &currAirport) {
          while (!adjList[currAirport].empty()) {
            std::string nxtDest = adjList[currAirport].front();
            adjList[currAirport].pop_front();

            dfs(nxtDest);
          }

          ans.push_back(currAirport);
        };

    dfs("JFK");
    std::reverse(ans.begin(), ans.end());
    return ans;
  }
};

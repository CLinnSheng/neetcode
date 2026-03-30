#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

class Solution
{
  public:
    std::unordered_map<int, int> shortestPath(int n, std::vector<std::vector<int>> &edges, int src)
    {
        std::vector<bool> visited(n, false);
        std::unordered_map<int, int> distance;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>>
            minHeap;

        minHeap.emplace(0, src);

        // (distance, node) same as pq
        std::vector<std::vector<std::pair<int, int>>> adjList(n);
        for (const auto &edge : edges)
            adjList[edge[0]].emplace_back(edge[2], edge[1]);

        while (!minHeap.empty())
        {
            const auto currNode = minHeap.top();
            minHeap.pop();

            if (distance.count(currNode.second))
                continue;

            std::cout << currNode.second << '\t' << currNode.first << '\n';
            distance[currNode.second] = currNode.first;
            visited[currNode.second] = true;

            for (const auto &neigh : adjList[currNode.second])
            {
                if (visited[neigh.second])
                    continue;

                std::cout << neigh.second << '\t' << neigh.first << '\n';
                std::cout << "POPPING IN" << '\t' << neigh.first << '+' << currNode.first << '\t' << neigh.second << '\n';
                minHeap.emplace(neigh.first + currNode.first, neigh.second);
            }

            std::cout << "\n\nNEW LOOP\n\n";
        }

        for (int i{}; i < n; i++)
            if (distance.count(i) == 0)
                distance[i] = -1;

        return distance;
    }
};

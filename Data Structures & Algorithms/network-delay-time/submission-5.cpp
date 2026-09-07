#include <algorithm>
#include <climits>
#include <queue>
#include <utility>
#include <vector>

/*
 * Goal: Return the minimum time it takes to travel from source to all the n nodes
 *
 * So the naive way will be using dfs and try out all different path, but we can actually use dijkstra algorithm to
 * always choose to extend the current shorter path
 * Can use a minHeap to always get the shortest distance to get to the next node
 * */

struct Comparator
{
    bool operator()(const std::pair<int, int> &A, const std::pair<int, int> &B)
    {
        return A.second > B.second;
    }
};

class Solution
{
  public:
    int networkDelayTime(std::vector<std::vector<int>> &times, int n, int k)
    {
        std::vector<std::vector<std::pair<int, int>>> adjList(n + 1);
        for (const auto &time : times)
        {
            adjList[time[0]].push_back({time[1], time[2]});
        }

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Comparator> minHeap;
        std::vector<int> dists(n + 1, INT_MAX);
        dists[k] = 0;
        minHeap.push({k, 0});

        while (!minHeap.empty())
        {
            auto top = minHeap.top();
            minHeap.pop();

            auto currNode = top.first;
            auto currWeight = top.second;

            // Visit all the neighbor node
            for (const auto &neigh : adjList[currNode])
            {
                auto neighNode = neigh.first;
                int weight = currWeight + neigh.second;

                // Only visit it if it never visit or shorter time
                if (dists[neighNode] > weight)
                {
                    dists[neighNode] = weight;
                    minHeap.push({neighNode, weight});
                }
            }
        }

        int timeTaken = *std::max_element(dists.begin() + 1, dists.end());

        return timeTaken == INT_MAX ? -1 : timeTaken;
    }
};

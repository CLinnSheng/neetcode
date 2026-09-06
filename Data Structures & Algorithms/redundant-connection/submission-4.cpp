#include <unordered_set>
#include <vector>
/*
 * Find the number of count components, we can use union find algorithm to
 * construct each graph Then after that only find out the number of each
 * connected component
 * Construct the graph then only find out the number of connected graph from the parents array
 * Time Complexity: O(1)
 * */
class Solution
{

    int findParent(int currNode, std::vector<int> &parents)
    {
        if (currNode != parents[currNode])
        {
            parents[currNode] = findParent(parents[parents[currNode]], parents);
        }

        return parents[currNode];
    }

    bool unionFind(int node_1, int node_2, std::vector<int> &ranks, std::vector<int> &parents)
    {
        int parent_1 = findParent(node_1, parents);
        int parent_2 = findParent(node_2, parents);

        // Same parent, connected then nothing to do
        if (parent_1 == parent_2)
        {
            return false;
        }

        if (ranks[parent_1] > ranks[parent_2])
        {
            parents[parent_2] = parent_1;
            ranks[parent_1] += ranks[parent_2];
        }
        else
        {
            parents[parent_1] = parent_2;
            ranks[parent_2] += ranks[parent_1];
        }

        return true;
    }

  public:
    std::vector<int> findRedundantConnection(std::vector<std::vector<int>> &edges)
    {
        int n = edges.size();
        std::vector<int> parents(n + 1), ranks(n + 1, 1);
        for (int i{}; i < n; i++)
        {
            parents[i] = i;
        }

        // build teh graph
        for (const auto &edge : edges)
        {
            if (unionFind(edge[0], edge[1], ranks, parents) == false)
            {
                return edge;
            }
        }

        return {};
    }
};

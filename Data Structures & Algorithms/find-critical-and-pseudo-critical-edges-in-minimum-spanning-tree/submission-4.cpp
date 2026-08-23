#include <algorithm>
#include <numeric>
#include <vector>
/*
 * Find all the critical and pseudo-critical edges in the MST.
 * Critcal Edge: Deletion from the graph would cause the MST to increase
 * Pseudo-Critical Edge: Appear in some MST but not all.
 * Minimum Edges to form MST: V - 1 Edges
 *
 * 2 Way to build MST
 * 1. Kruskal: Greedy always choose the chepeast edge if it doesnt create a cycle
 * 2. Prim: Always chooses the cheapest edge that connect out current tree
 *
 * We choose Kruskal because we need to find the edge that causes MST becomes more expensive. So we need
 * to exclude every edge one by one. Thus Kruskal fits better because it work directly with edges
 *
 * First build the MST.
 * Then we will iterate through edge by including and excluding the edge to find out the critical and pseudo age
 * While Excluding Loop --> If form more expensive MST (including not connected graph) then is a critical edge
 * While Including Loop --> Same weight as the initial MST build, then this edge is pseudo because it appear in all MST
 * but not MST that is more expensive
 *
 * Time Complexity: O(E^2)
 * */
class UnionFind
{
  private:
    std::vector<int> ranks, parents;

  public:
    UnionFind(const int n) : ranks(n, 1), parents(n)
    {
        std::iota(parents.begin(), parents.end(), 0);
    }

    int findParent(const int node)
    {
        if (node != parents[node])
        {
            parents[node] = findParent(parents[parents[node]]);
        }

        return parents[node];
    }

    bool unionSet(const int node_1, const int node_2)
    {
        int parent_1 = findParent(node_1), parent_2 = findParent(node_2);

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

    std::vector<int> &getRanks()
    {
        return this->ranks;
    }
};

class Solution
{
  public:
    std::vector<std::vector<int>> findCriticalAndPseudoCriticalEdges(int n, std::vector<std::vector<int>> &edges)
    {
        // Push the index because we need it in the future to skip some edge
        for (int i{}; i < edges.size(); i++)
        {
            edges[i].emplace_back(i);
        }

        // Sort the edges, so we can always choose the cheapest edge
        // O(ElgE)
        std::sort(edges.begin(), edges.end(), [](auto &a, auto &b) { return a[2] < b[2]; });

        UnionFind unionFind(n);
        int mstWeight{};

        // Build the mst
        // O(E * V)
        for (const auto &edge : edges)
        {
            if (unionFind.unionSet(edge[0], edge[1]))
            {
                mstWeight += edge[2];
            }
        }

        std::vector<int> critical, pseudo;

        for (const auto &edge : edges)
        {
            // Try to form MST without current edge
            UnionFind unionFind_without{n};
            int mstWeight_temp{};

            for (const auto &otherEdge : edges)
            {
                // Skip the current edge
                if (edge[3] != otherEdge[3] && unionFind_without.unionSet(otherEdge[0], otherEdge[1]))
                {
                    mstWeight_temp += otherEdge[2];
                }
            }

            // Crtical Edge
            // More expensive MST
            // Edge cases graph not connected and weight become infinity
            if (mstWeight_temp > mstWeight ||
                *std::max_element(unionFind_without.getRanks().begin(), unionFind_without.getRanks().end()) != n)
            {
                critical.emplace_back(edge[3]);
                // This edge must be exist in all MST because without it cant form MST
                continue;
            }

            // Try to form with current edge
            UnionFind unionFind_with{n};
            unionFind_with.unionSet(edge[0], edge[1]);
            mstWeight_temp = edge[2];
            for (const auto &otherEdge : edges)
            {
                if (edge[3] != otherEdge[3] && unionFind_with.unionSet(otherEdge[0], otherEdge[1]))
                {
                    mstWeight_temp += otherEdge[2];
                }
            }

            // Pseudo if equal to MST
            if (mstWeight_temp == mstWeight)
            {
                pseudo.emplace_back(edge[3]);
            }
        }

        return {critical, pseudo};
    }
};

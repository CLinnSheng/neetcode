#include <vector>
/*
 * Check whether a tree is valid or not
 * A tree doesnt has a cycle, so what we can do is checking whether can we find a cycle
 * And also all the nodes must be connected
 * Just dfs the tree
 * And it must  has n - 1 edges
 * */
class Solution
{
    std::vector<bool> visited;

  public:
    bool validTree(int n, std::vector<std::vector<int>> &edges)
    {
        // Base case
        if (edges.size() != n - 1)
        {
            return false;
        }

        std::vector<std::vector<int>> adjList(n);
        // build adjList from undirected edges
        for (const auto &edge : edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        visited = std::vector<bool>(n, false);

        // try to dfs from all nodes & only go for unvisited node
        for (int i{}; i < n; i++)
        {
            if (visited[i] == false && !dfs(adjList, i, -1))
            {
                return false;
            }
        }

        return true;
    }

    bool dfs(const std::vector<std::vector<int>> &adjList, int currNode, int parenNode)
    {
        if (visited[currNode])
        {
            return false;
        }

        // mark as visited
        visited[currNode] = true;

        // Traverse all its child node
        // Need to handle when neigh is equal to currNode node bcause the edges are undirected
        for (const auto neigh : adjList[currNode])
        {
            if (neigh != parenNode && !dfs(adjList, neigh, currNode))
            {
                return false;
            }
        }

        return true;
    }
};

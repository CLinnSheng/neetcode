/*
Find all the nodes that as root and has min height
The Brute Force way will just simply treats every node as the root and find its height
Time Complexity: O(n^2)

If we observe the tree,
The leaves that are treated as nodes will always result with the max height trees
So what we can do is to prune the tree start from the leaf
Another importnat observation is there is only 2 possible nodes count left if we keep removing from the leaves, it can either be only a single node left or 2 nodes
So in leyman term, the root must always be in the middle of the tree inorder to produce the min height trees. In order to find the roots, we can prune it from the leaves until we left it with only 1 node or 2 nodes at max. (Why not > 2? If we have 3 for instance we still can continue to prune it to left with only 1 node)
Time Complexity: O(V + E) / O(n)
*/
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
       // Edge Case with only 1 node
       if (n == 1)
       {
            return {0};
       }

       // Build the adj List 
       std::unordered_map<int, std::vector<int>> adjList;
       for (const auto& edge : edges)
       {
            adjList[edge[0]].emplace_back(edge[1]);
            adjList[edge[1]].emplace_back(edge[0]);
       }

        // Find out all the leaves
        std::deque<int> leaves;
        std::unordered_map<int, int> degree;
        for (const auto &[node, neigh] : adjList)
        {
            if (neigh.size() == 1)
            {
                leaves.emplace_back(node);
            }
            degree[node] = neigh.size();
        }

        // Pruning from the leaves
        while (leaves.size())
        {
            // Stopping Condition can either left with 1 or 2 nodes
            if (n <= 2)
            {
                return std::vector<int>(leaves.begin(), leaves.end());
            }

            int cnt = leaves.size();

            while (cnt)
            {
                int leaf = leaves.front();
                leaves.pop_front();
                n--;

                // Find its neigh and updates its degree
                for (const auto &neigh : adjList[leaf])
                {
                    degree[neigh]--;

                    // Append the leaf again
                    if (degree[neigh] == 1)
                    {
                        leaves.emplace_back(neigh);
                    }
                }

                cnt--;
            }
        }
    }
};
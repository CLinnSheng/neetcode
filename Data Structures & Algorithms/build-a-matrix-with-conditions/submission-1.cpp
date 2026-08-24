#include <deque>
#include <vector>
/*
 * rowConditions[i] = [above[i], below[i]]
 * colConditions[i] = [left[i], right[i]].
 * Build a KxK matrix that contains each of the numbers from 1 to K exactly once. Remaining cells fill with `0`
 * number above[i] should appear in a row strictly above the row at which the number below[i] appear for all i from 0 to
 * n - 1 number left[i] should appear in a column strictly to the left to the col  at which the number right[i] appear
 * for all i from 0 to m - 1
 *
 * Intuition:
 * We got the condition, so its like what comes before what
 * Then we can apply these number as nodes and connect it with edge that means node A comes before node B
 * Which means number A must be on top of number B
 * We can use topological sort on how to build the orders of number
 * Time Complexity: O(k^2 + n + m)
 * */
class Solution
{
  private:
    std::vector<int> topologicalSort(const int k, const std::vector<std::vector<int>> &edges)
    {
        std::vector<int> inDegree(k + 1, 0);
        std::vector<std::vector<int>> graph(k + 1);

        for (const auto &edge : edges)
        {
            graph[edge[0]].emplace_back(edge[1]);
            inDegree[edge[1]]++;
        }

        // Topological Sort
        std::deque<int> queue;
        for (int i{1}; i <= k; i++)
        {
            if (inDegree[i] == 0)
            {
                queue.emplace_back(i);
            }
        }

        std::vector<int> order;
        while (!queue.empty())
        {
            int currNum = queue.front();
            queue.pop_front();
            order.emplace_back(currNum);

            // Pop the current element from the queue and decrement the inDegree of its neigh
            for (const auto &neigh : graph[currNum])
            {
                inDegree[neigh]--;

                // Push into the queue if is 0
                if (inDegree[neigh] == 0)
                {
                    queue.emplace_back(neigh);
                }
            }
        }

        // Couldnt traverse all node means fail to build the matrix
        if (order.size() != k)
        {
            return {};
        }
        return order;
    }

  public:
    std::vector<std::vector<int>> buildMatrix(int k, std::vector<std::vector<int>> &rowConditions,
                                              std::vector<std::vector<int>> &colConditions)
    {
        // O(n)
        std::vector<int> rowOrder = topologicalSort(k, rowConditions);
        if (rowOrder.empty())
        {
            return {};
        }

        // O(m)
        std::vector<int> colOrder = topologicalSort(k, colConditions);
        if (colOrder.empty())
        {
            return {};
        }

        std::vector<std::vector<int>> matrix(k, std::vector<int>(k, 0));

        // Mapping the index of each number
        std::vector<int> rowPosition(k + 1);
        for (int i{}; i < k; i++)
        {
            rowPosition[rowOrder[i]] = i;
        }

        std::vector<int> colPosition(k + 1);
        for (int i{}; i < k; i++)
        {
            colPosition[colOrder[i]] = i;
        }

        // Build the matrix
        // O(k^2)
        for (int i{1}; i <= k; i++)
        {
            matrix[rowPosition[i]][colPosition[i]] = i;
        }

        return matrix;
    }
};

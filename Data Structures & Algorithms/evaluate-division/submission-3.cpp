/*
Ai/Bi = values[i]
Return the answers to all queries, if answer cannot be determined return -1
So we have to derive the values for each variable from equations and values
Then after that we can easily iterate through the query

Intuition:
We can think of each variable as a node and link it in the graph
For instance: A / B is equivalent to the node A link to node B then we got k
and in another way B / A is just 1 / k
And it also solves like A / C where we can achieve it by A / B * B / C simply just run the graph from A -> B -> C then we get the answer of A / C
*/
class Solution {
private:
    double dfs(const std::string& currNode, const std::string& targetNode, double accumVal, std::unordered_set<std::string>& visited, const std::unordered_map<std::string, std::vector<std::pair<std::string, double>>>& adjList)
    {
        // Base Case
        if (currNode == targetNode && adjList.count(currNode) != 0)
        {
            return accumVal;
        }

        // Mark as visited so no cycle
        visited.insert(currNode);

        // Check whether this node has neighboring nodes or not
        if (adjList.count(currNode) == 0)
        {
            return -1;
        }

        // Visit neighboring nodes
        for (const auto &node : adjList.at(currNode))
        {
            if (visited.find(node.first) == visited.end())
            {
                double res = dfs(node.first, targetNode, node.second * accumVal, visited, adjList);

                if (res == -1)
                {
                    continue;
                }

                return res;
            }
        }

        return -1;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // Building the graph
        std::unordered_map<std::string, std::vector<std::pair<string, double>>> adjList;
        for (int i{}; i < equations.size(); i++)
        {
            auto& equation = equations[i];

            // Store both direction because it will be useful when answering the query
            adjList[equation[0]].push_back({equation[1], values[i]});
            adjList[equation[1]].push_back({equation[0], 1 / values[i]});
        }

        std::vector<double> ans;
        for (const auto &query : queries)
        {
            // Check whether there is a path from query[0] to query[1] or not
            std::unordered_set<std::string> visited;
            ans.emplace_back(dfs(query[0], query[1], 1.0, visited, adjList));
        }

        return ans;
    }
};
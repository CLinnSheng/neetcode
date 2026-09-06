/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
/*
 * We can use dfs to travers down the graph and build the clone node while we traverse down
 * Some nodes might have the same neigh, to prevent doing double work, we can keep track of the new_node, so we directly
 * return it
 *
 * Time Comeplxity: O(V + E) traversingall the edges and nodes
 * */
#include <unordered_map>
class Solution
{
    std::unordered_map<Node *, Node *> mp;

  public:
    Node *cloneGraph(Node *node)
    {
        return dfs(node);
    }

    Node *dfs(Node *node)
    {
        if (node == nullptr)
        {
            return node;
        }

        if (mp.find(node) != mp.end())
        {
            return mp[node];
        }

        Node *newNode = new Node(node->val);
        mp[node] = newNode;

        // Visit all the neigh bors
        for (const auto neigh : node->neighbors)
        {
            newNode->neighbors.push_back(dfs(neigh));
        }

        return newNode;
    }
};

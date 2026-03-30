/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

/*
Intuition:
use recursive dfs to check
*/
class Solution {
private:
    Node* helper(const std::vector<std::vector<int>>& grid, int n, const int row, const int col)
    {
        bool allEqual{true};

        // Check whether the grid n * n has same value or not
        for (int i{}; i < n; i++)
            for (int j{}; j < n; j++)
                if (grid[row + i][col + j] != grid[row][col])
                {
                    allEqual = false;
                    break;
                }

        if (allEqual)
            return new Node(grid[row][col] == 1, true);

        Node* topLeft = helper(grid, n / 2, row, col);
        Node* topRight = helper(grid, n / 2, row, col + n / 2);
        Node* bottomLeft = helper(grid, n / 2, row + n / 2, col);
        Node* bottomRight = helper(grid, n / 2, row + n / 2, col + n / 2);

        return new Node(grid[row][col] == 1, false, topLeft, topRight, bottomLeft, bottomRight);
    }
public:
    Node* construct(vector<vector<int>>& grid) 
    {
        return helper(grid, grid.size(), 0, 0);
    }
};
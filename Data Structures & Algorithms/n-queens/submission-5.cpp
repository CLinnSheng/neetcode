#include <string>
#include <unordered_set>
#include <vector>
using std::vector, std::string;
/*
 * Find alll distinct solutions
 * "all" --> means dfs and backtrack whenever we find the solution
 * */
class Solution
{
  public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> subset(n, string(n, '.'));

        // use set to check whether is it a valid cell or not in o(1)
        std::unordered_set<int> posDiag, negDiag, cols;

        dfs(ans, subset, cols, posDiag, negDiag, 0, n);
        return ans;
    }

    void dfs(vector<vector<string>> &ans, vector<string> &subset, std::unordered_set<int> &cols,
             std::unordered_set<int> &posDiag, std::unordered_set<int> &negDiag, int row, int n)
    {
        // Iterate through every row then on each row try each col

        if (row == n)
        {
            ans.push_back(subset);
            return;
        }

        for (int col{}; col < n; col++)
        {
            if (!cols.count(col) && !posDiag.count(row + col) && !negDiag.count(row - col))
            {
                cols.insert(col);
                posDiag.insert(row + col);
                negDiag.insert(row - col);

                subset[row][col] = 'Q';
                dfs(ans, subset, cols, posDiag, negDiag, row + 1, n);

                cols.erase(col);
                posDiag.erase(row + col);
                negDiag.erase(row - col);
                subset[row][col] = '.';
            }
        }
    }
};

#include <functional>
#include <string>
#include <unordered_set>
#include <vector>

/*
 * Goal: Return all distinct solution to the n-queens puzzle
 *
 * Intuition:
 * This is actually a tree decision problem, at each cell we can choose to place the queen or not and then keep dfs
 * Once we reach a state where we cannot proceed we can backtrack to try other cell.
 * Time Complexity: O(n^2)
 * */
class Solution
{
  public:
    std::vector<std::vector<std::string>> solveNQueens(int n)
    {
        if (!n)
            return {};

        // A hash set to track the placed and restricted region
        std::unordered_set<int> cols, diagonal1, diagonal2;
        std::vector<std::string> steps(n, std::string(n, '.'));
        std::vector<std::vector<std::string>> answer;

        std::function<void(const int &)> dfs_backtracking = [&](const int &row) {
            if (row == n)
            {
                answer.emplace_back(steps);
                return;
            }

            // Iterating through the columns of the specific row
            for (int c{}; c < n; c++)
            {
                // Checking
                if (cols.count(c) == 0 && diagonal1.count(c + row) == 0 && diagonal2.count(c - row) == 0)
                {
                    cols.insert(c);
                    // 2 direction of diagonal
                    diagonal1.insert(c + row);
                    diagonal2.insert(c - row);
                    steps[row][c] = 'Q';

                    dfs_backtracking(row + 1);

                    // backtracking
                    cols.erase(c);
                    diagonal1.erase(c + row);
                    diagonal2.erase(c - row);
                    steps[row][c] = '.';
                }
            }
        };
        dfs_backtracking(0);
        return answer;
    }
};

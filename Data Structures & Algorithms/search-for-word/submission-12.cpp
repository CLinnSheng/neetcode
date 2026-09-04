#include <string>
#include <vector>
using std::vector, std::string;
/*
 * We can use backtracking once we find the first character and just dfs and backtrack if couldnt solve it.
 * We also need to keep track of the cell we visited so dont end up in a loop
 * */
class Solution
{
  public:
    const vector<std::pair<int, int>> DIRECTIONS{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    bool exist(vector<vector<char>> &board, string word)
    {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

        for (int r{}; r < board.size(); r++)
        {
            for (int c{}; c < board[r].size(); c++)
            {
                if (board[r][c] == word[0] && dfs(board, visited, word, r, c, 1))
                {
                    return true;
                }
            }
        }

        return false;
    }

    bool dfs(const vector<vector<char>> &board, vector<vector<bool>> &visited, const string &word, int row, int col,
             int index)
    {
        if (index == word.length())
        {
            return true;
        }

        visited[row][col] = true;

        for (const auto direction : DIRECTIONS)
        {
            int new_row = direction.first + row;
            int new_col = direction.second + col;

            if (new_row < 0 || new_col < 0 || new_row >= board.size() || new_col >= board[new_row].size() ||
                visited[new_row][new_col] || board[new_row][new_col] != word[index])
            {
                continue;
            }

            visited[new_row][new_col] = true;
            if (dfs(board, visited, word, new_row, new_col, index + 1))
            {
                return true;
            }

            visited[new_row][new_col] = false;
        }

        visited[row][col] = false;

        return false;
    }
};

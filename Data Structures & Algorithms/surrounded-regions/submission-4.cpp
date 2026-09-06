#include <utility>
#include <vector>
using std::vector;
/*
 * Replace all the `O` with `X` in place for those cell surrounded by `X`
 * Instead of traversing from the inside why not from the outside, because it is guaranteed that cells wont be
 * surrounded for the cells from boudnary Just dfs from the boundaries cell
 * */
class Solution
{
  public:
    const vector<std::pair<int, int>> DIRECTIONS{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int ROWS, COLS;

    void solve(vector<vector<char>> &board)
    {
        ROWS = board.size(), COLS = board[0].size();

        // DFS from the boundary
        for (int row{}; row < ROWS; row++)
        {
            for (int col{}; col < COLS; col++)
            {
                if (row == 0 || row == ROWS - 1 || ((row != 0 && row != ROWS - 1 && (col == 0 || col == COLS - 1))))
                {
                    if (board[row][col] == 'O')
                    {
                        dfs(board, row, col);
                    }
                }
            }
        }

        // Mark all those cell that arent visited to 'X'
        for (int row{}; row < ROWS; row++)
        {
            for (int col{}; col < COLS; col++)
            {
                if (board[row][col] == 'O')
                {
                    board[row][col] = 'X';
                }
            }
        }

        // Mark 'A' back to 'O'
        for (int row{}; row < ROWS; row++)
        {
            for (int col{}; col < COLS; col++)
            {
                if (board[row][col] == 'A')
                {
                    board[row][col] = 'O';
                }
            }
        }
    }

    void dfs(vector<vector<char>> &board, int row, int col)
    {
        // mark visited
        board[row][col] = 'A';

        for (const auto direction : DIRECTIONS)
        {
            int new_r = row + direction.first, new_c = col + direction.second;

            if (new_r < 0 || new_c < 0 || new_r >= ROWS || new_c >= COLS || board[new_r][new_c] != 'O')
            {
                continue;
            }

            dfs(board, new_r, new_c);
        }
    }
};

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        // Check Row, Column & Box
        // Can use hash set
        std::vector<std::unordered_set<int>> row(9), col(9), box(9);

        for (int i{}; i < 9; i++)
        {
            for (int j{}; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    continue;
                }

                int val = board[i][j] - '0';
                int box_index = i / 3 * 3 + j / 3;

                if (row[i].count(val))
                {
                    return false;
                }
                if (col[j].count(val))
                {
                    return false;
                }
                if (box[box_index].count(val))
                {
                    return false;
                }

                row[i].insert(val);
                col[j].insert(val);
                box[box_index].insert(val);
            }
        }   
        return true; 
    }
};

class Solution {
public:
// Must have 3 arrays to store the particular element
// 1 for row, 1 for column and 1 for the particular 3x3 box
// need find a data structure that can store the existence of a element
// --> set

    bool isValidSudoku(vector<vector<char>>& board) {

        ios_base :: sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        // Since for row we have 9 row, therefore we can use array of set
        vector<unordered_set<int>> row(9), col(9), box(9);

        int size = board.size();

        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++){

                if (board[i][j] == '.') continue;

            // Math for finding the 3x3 box it will be
                int pos = i / 3 * 3 + j / 3;
                int val = board[i][j] - '0';

                if (row[i].count(val) || col[j].count(val) || box[pos].count(val))
                    return false;
                else{
                    row[i].insert(val);
                    col[j].insert(val);
                    box[pos].insert(val);
                }

            }

        return true;

    }
};

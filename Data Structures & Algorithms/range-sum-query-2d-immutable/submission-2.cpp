class NumMatrix {
public:
    std::vector<std::vector<int>> matrix;
    NumMatrix(vector<vector<int>>& matrix) {
        this->matrix = matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ROWS = matrix.size(), COLS = matrix[0].size();
        int sum{};

        for (int row = row1; row <= row2; row++)
        {
            for (int col = col1; col <= col2; col++)
            {
                sum += matrix[row][col];
            }
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
#include <vector>
using std::vector;
/*
 * Searching the target inside a matrix
 * Important observation is the matrix is sorted
 * Each row is sorted in ascending order and first integer of every row is greater than the last integer of the previous
 * row. Since is sorted, we can make use of binary search First we need to find the exact row where the target lives in
 * Then after taht only search inside the row
 * */
class Solution
{
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int ROWS = matrix.size(), COLS = matrix[0].size();

        // Finding the rows
        int left{}, right = ROWS - 1;
        int row{};

        while (left <= right)
        {
            int middle = left + (right - left) / 2;

            // Check whether target falls in this row or not
            if (matrix[middle][0] <= target && matrix[middle][COLS - 1] >= target)
            {
                row = middle;
                break;
            }
            else if (matrix[middle][0] > target)
            {
                right = middle - 1;
            }
            else if (matrix[middle][COLS - 1] < target)
            {
                left = middle + 1;
            }
        }

        if (left > right)
        {
            return false;
        }

        left = 0;
        right = COLS - 1;

        while (left <= right)
        {
            int middle = left + (right - left) / 2;

            if (matrix[row][middle] == target)
            {
                return true;
            }
            else if (matrix[row][middle] > target)
            {
                right = middle - 1;
            }
            else
            {
                left = middle + 1;
            }
        }

        return false;
    }
};

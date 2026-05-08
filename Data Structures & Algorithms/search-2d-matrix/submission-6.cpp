class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        // The matrix is sorted in each row
        // Brute force will just go through every single cell
        // How can we make use of the sorted property? --> Binary Search
        // Find the correct row first then only find the correct nubmer in that row

        int ROWS = matrix.size(), COLS = matrix[0].size();

        // Finding the correct row
        int left{}, right{ROWS - 1};
        int targetedRow{-1};

        while (left <= right)
        {
            int middle = left + (right - left) / 2;

            if (matrix[middle][0] <= target && matrix[middle][COLS - 1] >= target)
            {
                targetedRow = middle;
                break;
            }
            // Determine through the last element
            else if (matrix[middle][COLS - 1] > target)
            {
                right = middle - 1;
            }
            else
            {
                left = middle + 1;
            }
        }

        if (targetedRow == -1)
        {
            return false;
        }

        // Once find the row, do binary search on that row
        left = 0;
        right = COLS - 1;

        while (left <= right)
        {
            int middle = left + (right - left) / 2;

            if (matrix[targetedRow][middle] == target)
            {
                return true;
            }
            else if (matrix[targetedRow][middle] > target)
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

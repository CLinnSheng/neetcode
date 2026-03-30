/*
Goal: Check whether the target exsits on the matrix or not

Intuition:
The matrix is sorted.
Since it is sorted we can straight apply using binary search, but how do we do it in a 2d matrix?
So the approach will be first find which row it at.
Then only serach through the row.
Time Complexity: O(lgmn)
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int ROWS(matrix.size()), COLS(matrix[0].size());

        // Find the row first
        int row, left{}, right{ROWS - 1};
        while (left <= right)
        {
            int middle(left + (right - left)/2);

            // A little bit tweak of on how to determine
            // Check whether is it in between the min and max of the row
            if (matrix[middle][0] > target)
                right = middle - 1;
            else if (matrix[middle][COLS - 1] < target)
                left = middle + 1;
            else
            {
                row = middle;
                break;
            }
        }

        // if couldnt find the exact row where it is in between the first and last elmeent
        if (left > right)
            return false;

        // Binary search on the row
        left = 0;
        right = COLS - 1;
        while (left <= right)
        {
            int middle(left + (right - left) / 2);

            if (matrix[row][middle] == target)
                return true;
            else if (matrix[row][middle] > target)
                right = middle - 1;
            else
                left = middle + 1;
        }
        return false;    
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m -1;
        int row;

        // Check at which row
        while (left <= right) // if only 1 row
        {
            int middle(left + (right - left) / 2);

            if (matrix[middle][0] > target)
            {
                right = middle - 1;
            }
            else if (matrix[middle][n - 1] < target)
            {
                left = middle + 1;
            }
            else
            {
                row = middle;
                break;
            }
        }

        if (left > right)
        {
            return false;
        }

        left = 0;
        right = n - 1;
        
        while (left <= right)
        {
            int middle = (left + (right - left) / 2);

            if (matrix[row][middle] > target)
            {
                right = middle - 1;
            }
            else if (matrix[row][middle] < target)
            {
                left = middle + 1;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};

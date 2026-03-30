#include <vector>
/*
Goal: Check whether is target in the 2D matrix or not

Intuition: Given that each row in the 2d matrix is sorted in ascending order
The first integer of each row is greater than the last integer of the previous row.
First we must find out it belongs to each row then only saerch for the particular row
*/

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) 
    {
        int n_row = matrix.size(), n_col = matrix[0].size();
        
        // Checking which row it belongs to
        int left = 0, right = n_row - 1;
        int middle;
        while (left <= right) {
            
            middle = left + (right - left) / 2;
            
            if (matrix[middle][0] > target) right = middle - 1;
            else if (matrix[middle][n_col - 1] < target) left = middle + 1;
            else break; // found the row it belongs

        }
        
        if (left > right) return false;
        left = 0, right = n_col - 1;

        while (left <= right) {

            int middle_index = left + (right - left) / 2;

            if (matrix[middle][middle_index] > target) right = middle_index - 1;
            else if (matrix[middle][middle_index] < target) left = middle_index + 1;
            else return true;

        }

        return false;
    }
};
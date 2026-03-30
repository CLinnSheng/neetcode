/*
Observation:
1. Array is Sorted in ascending order
2. index 1 & index 2 cannot equal

Intuition:
Since array is sorted, we need to make use of it.
Since only have exactly one valid solution. We can use 2 pointer one from the left and another from the right
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int size = numbers.size();
        int left{}, right{size - 1};

        while (left < right)
        {
            int sum = numbers[left] + numbers[right];

            if (sum == target)
            {
                return {left + 1, right + 1};
            }
            else if (sum > target)
            {
                right--;
            }
            else
            {
                left++;
            }
        }    
        return {};
    }
};

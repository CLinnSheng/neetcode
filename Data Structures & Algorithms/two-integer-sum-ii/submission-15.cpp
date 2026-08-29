#include <vector>
using std::vector;
/*
 * Find the number that add up to target
 * So array is sorted.
 * Make use of that property. Can have 2 pointer in the front and at the end
 * */
class Solution
{
  public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int n = numbers.size();
        int left{}, right = n - 1;

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

#include <algorithm>
#include <vector>

/*
 * Goal: Return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k & j != k && nums[i] + nums[j] +
 * nums[k] == 0
 * NOTE: Cannot contain duplicate triplets
 *
 * Intuition:
 * The most straightaway approach will be using triple loops to try out all the possible triplets.
 * How can we optimize this? From O(n^3) --> O(n^2) or even better
 *
 * The approach i can think of is actually using how we solve Two Sum
 * So we need to sort it first to simplify the process since order doesnt matter and we only need the indices
 * Since the array is sorted, we dont have to consider the num that is already greater than 0.
 * So what we will do is basically the same as Two Sum but with another pointer that act as the pivot.
 * We also need to handle duplicate triplets
 * Time Complexity: O(n^2)
 * */
class Solution
{
  public:
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());
        int size = nums.size();
        std::vector<std::vector<int>> ans;

        // Basically use the same approach of 2 sum by this time we only lock one and do 2 sum
        for (int i{}; i < size - 2; i++)
        {
            // Base Case
            if (nums[i] > 0)
            {
                break;
            }

            while (i > 0 && nums[i] == nums[i - 1])
            {
                i++;    
            }

            // Apply 2 sum
            int left{i + 1}, right{size - 1};
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0)
                {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left++;

                    while (nums[left] == nums[left - 1])
                    {
                        left++;
                    }
                }
                else if (sum > 0)
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }


        }
        return ans;
    }
};

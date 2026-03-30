/*
Split nums in to k non empty subarray such that the largest sum is minimized

Goal: Return the minimized largest sum of split

Intuition:
Observation the nums is not sorted and need to form subarray so order does matter
The possible sum is from the smallest elmeent in the array because an element itself also consider
a subarray to the sum of all the elements.
From here, we see there is a range we can apply binary search on here.
Then for the formation of subarray is simple we just check whether is it still within the maximum or not
since it is a contiguous subarray
*/
class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int left{*std::max_element(nums.begin(), nums.end())}, right(std::accumulate(nums.begin(), nums.end(), 0));

        auto helper = [&](const int& maxSum)
        {
            int subarray{1}, currSum{};

            for (const auto& num : nums)
            {
                currSum += num;

                if (currSum > maxSum)
                {
                    subarray++;
                    if (subarray > k)
                        return false;

                    currSum = num; 
                }
            }
            return true;
        };

        int ans{};

        while (left <= right)
        {
            int middle(left + (right - left) / 2);

            if (helper(middle))
            {
                ans = middle;
                right = middle - 1;
            }
            else
                left = middle + 1;
        }
        return ans;
    }
};
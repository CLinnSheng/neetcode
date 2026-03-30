/*
A bit similar to 2sum & 3sum
Since we want unique quadruplets --> Sorting will ease the problem
We can do a nested loop like 3sum so
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        std::sort(nums.begin(), nums.end());
        int size = nums.size();

        if (size < 4)
        {
            return {};
        }

        std::vector<std::vector<int>> answer;

        for (int i{}; i < size - 3; i++)
        {
            // Base Case
            if (nums[i] > target)
            {
                break;
            }

            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            // 3 Sum
            for (int j{i + 1}; j < size - 2; j++)
            {
                // Only skip the second 1
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }
                int sum = nums[i] + nums[j];
                int left{j + 1}, right{size - 1};

                while (left < right)
                {
                    int currSum = sum + nums[left] + nums[right];
                    
                    if (currSum == target)
                    {
                        answer.push_back({nums[i], nums[j], nums[left], nums[right]});

                        left++;
                        while (left < right && nums[left] == nums[left - 1])
                        {
                            left++;
                        }
                    }
                    else if (currSum > target)
                    {
                        right--;
                    }
                    else
                    {
                        left++;
                    }
                }


            }
        }

        return answer;
    }
};
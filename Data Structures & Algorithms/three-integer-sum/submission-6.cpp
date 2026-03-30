class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n(nums.size());

        for (int i{}; i < n - 2; i++)
        {
            // Early Stopping
            if (nums[i] > 0)
            {
                break;
            }

            // Prevent duplicate triplet and compare with previous element so that we will process the repeated elmeent oncee
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int left{i + 1}, right{n - 1};
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum > 0)
                {
                    right--;
                }
                else if (sum < 0)
                {
                    left++;
                }
                else
                {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;

                    // Prevent duplicate
                    while (left < right && nums[left] == nums[left - 1])
                    {
                        left++;
                    }
                }
            }
        }
        return ans;
    }
};

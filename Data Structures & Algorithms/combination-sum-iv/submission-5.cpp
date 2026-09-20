class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
       // At each index we can either include it or skip it
       // From the recursion, we can see some subproblem is solved multiple time
       // We can cache it and reuse it
       // Time complexity: O(n * t)
       // Possible t choices and each choices we loop through the array and thus t * n
       vector<int> cache(target + 1, -1);

        return dfs(nums,target, 0, cache);
    }

    int dfs(const std::vector<int>& nums, int target, int currSum, vector<int>& cache)
    {
        if (currSum > target)
        {
            return 0;
        }

        if (currSum == target)
        {
            return 1;
        }

        if (cache[currSum] != -1)
        {
            return cache[currSum];
        }


        int cnt{};
        for (int i{}; i < nums.size(); i++)
        {
            cnt += dfs(nums, target, currSum + nums[i], cache);

        }

        return cache[currSum] = cnt;
    }
};
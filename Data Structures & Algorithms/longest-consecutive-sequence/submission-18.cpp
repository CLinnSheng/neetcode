class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Easiest way is just sort the element first and then iterate through the element but this will cose O(nlgn)
        // Approach 1
        // int ans{1}, n(nums.size()), ptr{};
        // if (n == 0)
        // {
        //     return 0;
        // }
        // int curr{nums[0]}, lens{};
        // sort(nums.begin(), nums.end());
        // while (ptr < n)
        // {
        //     if (curr != nums[ptr])
        //     {
        //         lens = 0;
        //         curr = nums[ptr];
        //     }

        //     while (ptr < n && nums[ptr] == curr)
        //     {
        //         ptr++;
        //     }
        //     curr++;
        //     lens++;
        //     ans = std::max(ans, lens);
        // }
        // return ans;
    
        // Approach 2
        // If you notice from approach 1 what we really care is the number previous and the number after exists or not
        // so instead of go and check every number why dont we have a hash set that store all nubmer in the set
        // then we only check from the first number

        std::unordered_set<int> hashset(nums.begin(), nums.end());
        int ans{1};

        if (hashset.empty())
        {
            return 0;
        }

        for (const auto& i : hashset)
        {
            int len{1};
            if (!hashset.count(i - 1))
            {
                int curr = i;
                while (hashset.count(curr + 1))
                {
                    curr++;
                    len++;
                }
                ans = std::max(ans, len);
            }  
        }
        return ans;
    }
};

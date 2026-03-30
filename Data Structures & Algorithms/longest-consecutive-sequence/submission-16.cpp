class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Easiest way is just sort the element first and then iterate through the element but this will cose O(nlgn)
        // Approach 1
        int ans{1}, n(nums.size()), ptr{};

        if (n == 0)
        {
            return 0;
        }
        
        
        int curr{nums[0]}, lens{};

        sort(nums.begin(), nums.end());


        while (ptr < n)
        {
            if (curr != nums[ptr])
            {
                lens = 0;
                curr = nums[ptr];
            }

            while (ptr < n && nums[ptr] == curr)
            {
                ptr++;
            }

            curr++;
            lens++;
            ans = std::max(ans, lens);
        }
        return ans;
    }
};

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        // Brute force will be double looping
        // How can we reduce the loop to achieve O(n) or even O(nlgn)
        // But in this O(nlgn) will be impossible because the order does matter, so we cannot sort it.
        // So the only choice left is only O(n)
        // If you notice from brute force we doing checking of overlapping subarray.
        // Why not we store the prefix sum of subarray so that we can get teh sum of any subarray easily
        // by subtracting for instance subarray[i + 1:j] = prefix[j] - prefix[i]
        // Ok then we can store all tehse subarray sum into a hashmap because we iterate from left to right
        // At each index we can easily determine how many subarray before curent index has target - currentPrefixSum
        std::unordered_map<int, int> prefixMap;
        // IMPORTANT: Need to add mapping for getting 0
        prefixMap[0] = 1; // 1 way to get 0 intiially
        int ans{};
        int currSum{};

        for (const auto num : nums)
        {
            currSum += num;
            int diff = currSum - k;

            if (prefixMap.count(diff))
            {
                ans += prefixMap[diff];
            }

            prefixMap[currSum]++;
        }
        return ans;
    }
};
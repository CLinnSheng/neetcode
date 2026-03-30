class Solution {
public:
// sorted the array in descending order is easier compare to ascending order
// then iterate through the array
    int longestConsecutive(vector<int>& nums) {
        
        ios_base :: sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        unordered_set<int> s(nums.begin(), nums.end());

        int longest = 0;

        // try to find the smallest int of a sequence
        for (auto &i : nums){
            // if true then we know we can start by from this number
            int length = 0;
            if (!s.count(i - 1))
                while (s.count(i + length))
                    length++;

            longest = max(length, longest);

        }

        return longest;
    }
};

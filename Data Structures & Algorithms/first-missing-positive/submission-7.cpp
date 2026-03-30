class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // Brute force way will be just simply stored in a hash set and iterate from 1
        // O(n) time and O(n) space
        std::unordered_set<int> numbers(nums.begin(), nums.end());
        int curr{1};
        while (true)
        {
            if (numbers.count(curr))
            {
                curr++;
                continue;
            }
            return curr;
        }
        return -1;
    }
};
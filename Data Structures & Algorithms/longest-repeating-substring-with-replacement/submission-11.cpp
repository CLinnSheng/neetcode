class Solution {
public:
    int characterReplacement(string s, int k)
    {
        // About the same as finding the longest substring
        // But this time is with replacement and repeating characters
        // So we cant use hash set anymore but hash map
        // Since we want the longest repeating, so we will replace the least characters greedily.
        // Hence we will use var to keep track of that
        // Number of characters needed to be replace within a subarray will just simply be
        // right - left + 1 - max_frequency
        // if > k means we dont ahve enough number to replace
        // From here we can use dsliding window algo, just keep updating left until the window is valid
        int len = s.length();
        int left{}, right{};
        int ans{};
        std::unordered_map<char, int> mp;
        int maxFreq{};

        while (right < len)
        {
            mp[s[right]]++;
            // Update the most freq char in the curr window
            maxFreq = std::max(maxFreq, mp[s[right]]);

            // Check thw window is valid or not
            while (right - left + 1 - maxFreq > k)
            {
                // We dont need to update the maxFreq
                // Because we finding the longest substring with repeating character
                // The window might be invalid but we already find the longest
                mp[s[left]]--;
                left++;
            }

            ans = std::max(right - left + 1, ans);
            right++;
        }

        return ans;
    }
    
};

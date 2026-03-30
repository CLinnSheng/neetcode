class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        // Finding the longest substring wihtout duplicate character
        // Duplicate Character --> To check in O(1) we can use set
        // Brute force way will loop through every single subarray
        // Observe from the BF, we saw we do a lot of checking of overlapping subarray
        // Thus we can reduce it to O(n) by not checking overlapping array and iterate through it once
        // Use sliding window algo

        int len = s.length();
        if (len == 0)
        {
            return 0;
        }

        int left{}, right{};
        std::unordered_set<char> chars;
        int ans{}; 

        while (right < len)
        {
            if (chars.count(s[right]))
            {
                ans = std::max(ans, right - left);
                // Remove the existing word from the window
                while (left < right && chars.count(s[right]))
                {
                    chars.erase(s[left]);
                    left++;
                }
            }

            chars.insert(s[right]);
            right++;
        }

        return std::max(ans, right - left);
    }
};

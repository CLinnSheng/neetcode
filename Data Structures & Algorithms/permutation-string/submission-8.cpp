/*
Check if s2 contains a permutation of s1. In other ways check if permutation of s1 exists as a substring of s2.
1st Observation: Permutation of s1, so order doesnt matter, what really matter is the freq of each character in the string
2nd Observation: Substring of s2 --> Can use sliding window with length of s1
We can use a vector of 26 to check, so basically if every index equal to 0 then means contain s1
*/

class Solution {
public:
    bool helper(const std::vector<int>& arr)
    {
        for (const auto i : arr)
        {
            if (i != 0)
            {
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) 
    {
        // Base Case
        if (s1.length() > s2.length())
        {
            return false;
        }

        std::vector<int> arr(26, 0);
        for (const char c : s1)
        {
            arr[c - 'a']++;
        }

        int len1 = s1.length(), len2 = s2.length();
        int left{}, right{};
        while (right < len2)
        {
            // Include the value first
            arr[s2[right] - 'a']--;

            // Check the size
            if (right - left + 1 > len1)
            {
                // Remove the element
                arr[s2[left] - 'a']++;
                left++;
            }

            // Check the window
            if (right - left + 1 == len1 && helper(arr))
            {
                return true;
            }

            right++;
        }
        return false;
    }
};

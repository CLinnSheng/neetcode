class Solution {
public:
    string longestPalindrome(string s) {
        // Another way is using dp
        // Because if we observe, there have some overlapping to check whether this substring is palindrome or not
        // We can use a 2d array to cache it
        // dp[i][j] means from i to j is a palindrome
        int len = s.length();
        if (len == 1 || len == 0)
        {
            return s;
        }

        std::vector<std::vector<bool>> cache(len, std::vector<bool>(len, false));
        // Start from the back instead of the front
        // Because we need information of dp[i + 1][j - 1] as we already check the smaller substring, can just reuse

        int index{}, maxLen{};
        for (int i{len - 1}; i >= 0; i--)
        {
            for (int j{i}; j < len; j++)
            {
                // Equal String && handle even case and single word
                if (s[i] == s[j] && (j - i < 2 || cache[i + 1][j - 1]))
                {
                    if (j - i + 1 > maxLen)
                    {
                        maxLen = j - i + 1;
                        index = i;
                    }
                    
                    cache[i][j] = true;
                }
            }
        }

        return s.substr(index, maxLen);
    }
};

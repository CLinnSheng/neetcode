class Solution {
public:
    int countSubstrings(string s) {
       // Abit similar to finding the longest substring
       // Just some tweak, we just need to count and can use the dp pattern from before 
       int len = s.length();
       if (len == 1)
       {
            return 1;
       }

       int cnt{};
       std::vector<std::vector<bool>> dp(len, std::vector<bool>(len, false));

       for (int i{len - 1}; i >= 0; i--)
       {
            for (int j{i}; j < len; j++)
            {
                if (s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1]))
                {
                    cnt++;
                    dp[i][j] = true;
                }
            }
       }

        return cnt;
    }
};

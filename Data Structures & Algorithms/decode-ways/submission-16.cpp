class Solution {
public:
    int numDecodings(string s) {
       // Find the number of ways of decoding the string 
       // 1012 -> 10 & 1 & 2 or 10 & 12
       // Cannot start from 0
       // Ok so we know we got 26 alphabets
       // At each index we can choose to include it or not which means 1 letter or 2 letter
       // O(2^N)
       // If we observe from the dfs or recursive, we can see some subproblem is solving multiple times
       // So we can cache it
       // dp[i] simply means the number of ways decode from string i
       std::vector<int> dp(s.length(), -1);
       return dfs(0, s, dp);
    }

    int dfs(const int index, std::string& s, std::vector<int>& dp)
    {
        // Base case, only 1 way
        if (index == s.length())
        {
            return 1;
        }

        if (dp[index] != - 1)
        {
            return dp[index];
        }

        // If start from 0, then ignore it because we can include it in both single or double character
        if (s[index] == '0')
        {
            return 0;
        }

        // 1 letter
        int cnt = dfs(index + 1, s, dp);

        // Try include 2 letters
        // Make sure 2 character left and check when start with `1` and `2`
        if (index < s.length() - 1 && (s[index] == '1' || (s[index] == '2' && s[index + 1] < '7')))
        {
            cnt += dfs(index + 2, s, dp);
        }

        return dp[index] = cnt;
    }
};

/*
Return true if s3 is formed by interleaving s1 and s2 together or false
*/
class Solution {
   public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.length() != s1.length() + s2.length()) {
            return false;
        }

        if (s3.empty() && s1.empty() && s2.empty()) {
            return true;
        }

        // So each point of s3 we can choose to either pick s1 or s2
        // We can just naively solve it with recursion
        // Observation from the naive solution, we solving the subproblem more than once
        // Why dont we just cache it and reuse?
        // 3 information is passed down, but the ptr3 actually can derived from ptr1 + ptr2
        // So we can cache the result with just ptr1 and ptr2
        // dp[i][j] means that whether index i in s1 and index j in s2 can form s3?
        vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, -1));
        return recursion(s1, s2, s3, 0, 0, 0, dp);
    }

    bool recursion(const string& s1, const string& s2, const string& s3, int ptr1, int ptr2,
                   int ptr3, vector<vector<int>>& dp) {
        if (ptr3 == s3.length()) {
            return true;
        }

        if (dp[ptr1][ptr2] != -1)
        {
            return dp[ptr1][ptr2];
        }

        bool pick1{}, pick2{};
        // Pick s1 if can
        if (ptr1 < s1.length() && s1[ptr1] == s3[ptr3]) {
            pick1 = recursion(s1, s2, s3, ptr1 + 1, ptr2, ptr3 + 1, dp);
        }

        // Pick s2 if can
        if (ptr2 < s2.length() && s2[ptr2] == s3[ptr3]) {
            pick2 = recursion(s1, s2, s3, ptr1, ptr2 + 1, ptr3 + 1, dp);
        }

        return dp[ptr1][ptr2] = (pick1 || pick2)? 1 : 0;
    }
};

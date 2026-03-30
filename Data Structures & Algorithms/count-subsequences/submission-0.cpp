#include <string>
#include <vector>
/*
 * Goal: Return the number of distinct subsequences of s which equals t.
 *
 * Intuition:
 * At each index, we can either choose it or skip it. If is euqal then we only move the index on string t.
 * */
class Solution
{
  private:
    int dfs(std::string &s, std::string &t, std::vector<std::vector<int>> &cache, int i, int j)
    {
        if (j == t.size())
        {
            return 1;
        }

        if (i == s.size())
        {
            return 0;
        }

        if (cache[i][j] != -1)
        {
            return cache[i][j];
        }

        // Skip
        int cnt = dfs(s, t, cache, i + 1, j);

        if (s[i] == t[j])
        {
            cnt += dfs(s, t, cache, i + 1, j + 1);
        }

        return cache[i][j] = cnt;
    }

  public:
    int numDistinct(std::string s, std::string t)
    {
        std::vector<std::vector<int>> cache(s.size() + 1, std::vector<int>(t.size() + 1, -1));
        return dfs(s, t, cache, 0, 0);
    }
};

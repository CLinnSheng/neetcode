#include <algorithm>
#include <climits>
#include <string>
#include <vector>
using std::string, std::vector;

class Solution
{
  public:
    string stoneGameIII(vector<int> &stoneValue)
    {
        // We can do it in a recursive way by letting the player to choose up to 3 stone.
        // And then we take the min or max Score.
        // Since each player will play optimally
        // So whenever is Alice turn we want to take the Maximum and when Bob turns we want to take the Min
        // Observation from the recursive brute force approach, we can see that some subproblem is being solved multiple
        // times We can cache it and reuse it Two things is being pass down the stack which is the idnex and turns, so
        // we need a 2d array cache[i][j] simply means the maximum Amount from index at j turn
        // Time Complexity: O(3^n) -> O(n)

        vector<vector<int>> cache(stoneValue.size(), vector<int>(2, INT_MIN));

        int res = dfs(stoneValue, cache, 0, 1);

        if (res > 0)
        {
            return "Alice";
        }
        else if (res < 0)
        {
            return "Bob";
        }
        else
        {
            return "Tie";
        }
    }

    int dfs(const vector<int> &stoneValue, vector<vector<int>> &cache, int index, int alice_turn)
    {
        if (index >= stoneValue.size())
        {
            return 0;
        }

        if (cache[index][alice_turn] != INT_MIN)
        {
            return cache[index][alice_turn];
        }

        int sum{};
        int res = alice_turn ? INT_MIN : INT_MAX;

        for (int i{index}; i < std::min(index + 3, (int)stoneValue.size()); i++)
        {
            if (alice_turn)
            {
                sum += stoneValue[i];
                res = std::max(res, sum + dfs(stoneValue, cache, i + 1, 0));
            }
            else
            {
                sum -= stoneValue[i];
                res = std::min(res, sum + dfs(stoneValue, cache, i + 1, 1));
            }
        }

        return cache[index][alice_turn] = res;
    }
};

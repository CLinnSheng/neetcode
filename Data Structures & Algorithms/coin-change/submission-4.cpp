class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
       // At each point of time we have 3 choices, naive solution 
       // Observe from the recursive naive solution, subproblem is the amount
       // At some amount we find the minimum count multiple time
       // So what we can do is cache it
       std::vector<int> cache(amount + 1, -1);
       int ans = recursive(coins, amount, cache);
       return ans == 1e9? -1 : ans;
    }

    int recursive(const std::vector<int>& coins, int amount, std::vector<int>& cache)
    {
        // Base Case
        if (amount == 0)
        {
            return 0;
        }

        if (cache[amount] != -1)
        {
            return cache[amount];
        }

        int cnt = 1e9;

        for (const auto coin : coins)
        {
            // Only allocate if amount > coin
            if (coin <= amount)
            {
                cnt = std::min(cnt, recursive(coins, amount - coin, cache) + 1);
            }
        }

        return cache[amount] = cnt;
    }
};

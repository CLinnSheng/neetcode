class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Choose a single day to buy and sell
        // We can use sliding window method to get the best sell day, so in terms of buy day we alwayus try to buy low

        int left{}, right{1};
        int ans{};

        while (right < prices.size())
        {
            // Always try to buy the low, so we assume buying every single day
            // Then we get the highest selling day
            while (right < prices.size() && prices[right] > prices[left])
            {
                ans = std::max(ans, prices[right] - prices[left]);
                right++;
            }

            // Move the buy day
            left = right;
            right++;
        }
        return ans;
    }
};

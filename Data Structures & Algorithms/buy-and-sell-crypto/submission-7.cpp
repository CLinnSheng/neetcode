class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Choose a single day to buy and sell
        // We can use sliding window method to get the best sell day, so in terms of buy day we alwayus try to buy low

        int left{}, right{1};
        int ans{};

        while (right < prices.size())
        {
            while (right < prices.size() && prices[left] < prices[right])
            {
                ans = std::max(ans, prices[right] - prices[left]);
                right++;
            }

            left = right;
            right++;
        }
        return ans;
    }
};

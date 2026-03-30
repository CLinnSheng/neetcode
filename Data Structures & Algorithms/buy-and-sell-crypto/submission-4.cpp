class Solution {
public:
// Goal : Find the maximum profit on what day to buy and what day to sell
// Intuition: Use sliding window algorithm to find the best day to buy and best day to sell
// buy day < sell day
    int maxProfit(vector<int>& prices) {
        
        ios_base :: sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int days = prices.size();

        if (!days)  return 0;

        int profit = 0;

        int l = 0, r = 0;

        while (r < days){
            // then we can find the profit
            if (prices[r] > prices[l])
                profit = max(profit, prices[r] - prices[l]);
            else
            // Readjust the window because buy is higher than sell
            // Move the buy to the newest sale day
                l = r;

            r++;
        }

        return profit;
    }
};

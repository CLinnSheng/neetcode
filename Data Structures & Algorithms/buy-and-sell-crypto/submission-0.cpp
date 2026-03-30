class Solution {
public:
// price[i] price of the given stock on ith day
// Intuition: Maximize profit by choosing a day to buy and a different day in the future to sell

// Have two pointer and use sliding window algo
    int maxProfit(vector<int>& prices) {
        
        ios_base :: sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int max_profit= 0;

// left is the buy day and right is the sell day
// right > left
// Sliding window algo:
// left and right ptr
// Constraint: right > left (right is the sell day and left is the buy day)
// if sell > buy find the profit and update the maximum and increase the right value to increase the window size
// if sell < buy update the buy date equal to the sell date
// keep updating the sell day to try and error
        int left = 0, right = 0;

        while (right < prices.size()){
            
            if (prices[right] > prices[left])
                max_profit = max(max_profit, prices[right] - prices[left]);
            else
                left = right;

            right++;

        }

        return max_profit;
    }
};
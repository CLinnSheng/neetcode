/*
Goal: find the maximum profit you can achieve

Constraint:
1. Can only hold 1 stock at any time

Intuition:
Buy Low & Sell High.
We can buy and sell stock at any time, so is no restricted to can hold buy and once sell.
We can be greedy. To sell whenever the price is much more higher than the price we buy.
Because more order -> more price instead of the diff between the min & max
O(n)
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int profit{};

        for (int i{1}; i < prices.size(); i++)
        {
            if (prices[i] > prices[i - 1])
            {
                profit += (prices[i] - prices[i - 1]);
            }
        }
        return profit;     
    }
};
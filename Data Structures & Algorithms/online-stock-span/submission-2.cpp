/*
Span --> Stock's price in one day is the maximum number of consecutive days for which the
stock price was less than or equal to the price of that day.

Intuition:
We needto store the price stock of each day and the index does matter.
So we can use a stack as we can iterate through the day before in the correct order
Actually we can further optimize it, instead of iterate through every single days,
at each day we can store the span. So as long as the price is greater than the price before it,
the span before the day can just directly apply on it
Time Complexity: O(n)
*/
class StockSpanner {
public:
    std::deque<std::pair<int, int>> stocks;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ans{1};

        while (!stocks.empty() && price >= stocks.back().first)
        {
            ans += stocks.back().second;
            stocks.pop_back();
        }

        stocks.push_back({price, ans});

        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
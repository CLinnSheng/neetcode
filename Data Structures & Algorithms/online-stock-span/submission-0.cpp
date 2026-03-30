/*
Span --> Stock's price in one day is the maximum number of consecutive days for which the
stock price was less than or equal to the price of that day.

Intuition:
We needto store the price stock of each day and the index does matter.
So we can use a stack as we can iterate through the day before in the correct order
*/
class StockSpanner {
public:
    std::deque<int> stocks;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ans{1};

        std::deque<int> temp = stocks;
        while (!temp.empty() && price >= temp.back())
        {
            ans++;
            temp.pop_back();
        }

        stocks.push_back(price);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
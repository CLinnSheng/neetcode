class StockSpanner {
public:
    std::deque<int> st;
    StockSpanner() {
        
    }
    
    // Maximum number of consecutive day for which the stock price was less than
    // or equal to the price of that day
    int next(int price) {
        st.push_back(price);
        int cnt{};

        for (auto it = st.rbegin(); it != st.rend(); it++)
        {
            if (*it <= price)
            {
                cnt++;
            }
            else
            {
                break;
            }
        }

        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
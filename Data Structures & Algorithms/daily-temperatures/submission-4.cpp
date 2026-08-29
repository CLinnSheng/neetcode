#include <stack>
#include <vector>
using std::vector;
/*
 * Brute force will just simply using double loop
 * How can we make use of the information we just traversed?
 * Because we need information from the future to know when is the temperature is higher.
 * Think in the opposite way, if we cant have the information from the future, how about we use our past information?
 * Use a stack because we need the index, as we need the day diff.
 * We can have a decrement monotomic stack, so the stack can store those who is still finding its next higher
 * temperature day.
 * */
class Solution
{
  public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        std::stack<int> st;
        st.push(0);
        vector<int> ans(temperatures.size(), 0);

        for (int i{1}; i < temperatures.size(); i++)
        {
            while (!st.empty() && temperatures[st.top()] < temperatures[i])
            {
                ans[st.top()] = i - st.top();
                st.pop();
            }

            st.push(i);
        }

        return ans;
    }
};

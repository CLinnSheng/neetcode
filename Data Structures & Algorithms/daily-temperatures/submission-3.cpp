/*
Return an array rasult where result[i] is the number of days after the ith day before a warmer
in the future day
Ok so we will need to access the old --> Stack
We need a monotonic decreasing stack because if is increasing then it will just simply greater than the previous temperature
So the logic, will be keep pushing into the stack with the indices if is smaller until we notice greater eleemnt
then pop until is not longer greater than the element in the stack
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int days = temperatures.size();
        if (days == 1)
        {
            return {0};
        }
        std::vector<int> ans(days, 0);
        std::deque<int> st;

        for (int i{}; i < days; i++)
        {
            if (st.empty())
            {
                st.push_back(i);
            }
            else
            {
                if (temperatures[st.back()] > temperatures[i])
                {
                    st.push_back(i);
                }
                else
                {
                    while (!st.empty() && temperatures[st.back()] < temperatures[i])
                    {
                        ans[st.back()] = i - st.back();
                        st.pop_back();
                    }

                    st.push_back(i);
                }
            }
        }
        return ans;
    }
};

/*
Goal: Return an array result where result[i] is the number of day after the ith day before
a higher temperature appears on a future day.

Intuition:
So we need information for the past while traversing the array to find a temperature higher than it
So this lead me thinking of using a deque.
Ok So the stack basically we be in descending order.
Then for each day we will pop the stack until the temperature is not greater
Time Complexity: O(N)
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        int days(temperatures.size());
        std::vector<int> answer(days, 0);
        std::deque<std::pair<int, int>> stack;

        for (int day{}; day < days; day++)
        {
            while (!stack.empty() && temperatures[day] > stack.back().first)
            {
                auto temp{stack.back()};
                stack.pop_back();

                answer[temp.second] = day - temp.second;
            }

            stack.push_back({temperatures[day], day});
        }
        return answer;    
    }
};

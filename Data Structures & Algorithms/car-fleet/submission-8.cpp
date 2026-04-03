/*
One lane highway so the position does matter.
position array is not sorted --> so we need to find out exactly each car position
And the car speed is limited by the car in front of him
So the first thing we need to sort the car by position first
So basically we traverse the car from the least position, to check whether the first and second
car will be come one fleet is depends on whether the speed of 2nd car is it faster or slowr than it.
So this means that we need psat information which we can use a stack
The most easy measurement is use the timeTaken to reach the destination and the final stack will just become
the number of fleet.
*/
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) 
    {
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> minHeap;
        int n = position.size();
        for (int i{}; i < n; i++)
        {
            minHeap.push({position[i], speed[i]});
        }

        std::deque<float> st;

        while (!minHeap.empty())
        {
            auto [pos, spd] = minHeap.top();
            minHeap.pop();

            float timeTaken = float(target - pos) / spd;

            // Check the stack
            while (!st.empty() && st.back() <=  timeTaken)
            {
                std::cout << pos << '\t' << spd << '\n';
                st.pop_back();
            }

            st.push_back(timeTaken);
        }
        return st.size();
    }
};

// [0, 1, 4, 7]
// [1, 2, 2, 1]
// 10, 4.5,
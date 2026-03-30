/*
position[i] - position of ith car
speed[i] - speed of ith car
Car cannot catch up another car ahead of it. Can only at best drive at the same speed
Car Fleet - return the number of sets of cars driving at the same speed.

Goal: Return the number of different car fleets that will arrive at the destination

Intuition:
One key important is car cannot take over another car and will clump together at the same speed.
So this indicates that we needed the information of any car that we iterate through.
And then the value does matter which is the speed. This lead me to think of using Stack

How can we check whether the car will be lump together or becoming a car fleet?
We can make use of the target. So we can use the time taken it required to reach the target.
So we need to iterate the cars from the least position and then check whether the current car reqiured
time is longer or shorter than the previous car. If longer then pop out the old car, bccause the current car
is the frontmost and will form a car fleet with all of the car behind him.

Time Complexity: O(nlgn)
*/
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) 
    {
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> minHeap;
        for (int i{}; i < position.size(); i++)
            minHeap.push({position[i], speed[i]});

        std::deque<double> stack;

        while (!minHeap.empty())
        {
            auto currCar{minHeap.top()};
            minHeap.pop();

            double timeTaken((target - currCar.first) / float(currCar.second));

            while (!stack.empty() && timeTaken >= stack.back())
                stack.pop_back();

            stack.push_back(timeTaken);
        }
        return stack.size();
    }
};

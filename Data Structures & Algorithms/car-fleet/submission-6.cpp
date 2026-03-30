class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        std::deque<float> stack;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> minHeap;
        int n = position.size();

        for (int i{}; i < n; i++)
            minHeap.push({position[i], speed[i]});

        while (!minHeap.empty())
        {
            float timeTaken = (target - minHeap.top().first) / float(minHeap.top().second);
            minHeap.pop();
            
            while (!stack.empty() && timeTaken >= stack.back())
            {
                stack.pop_back();
            }

            stack.push_back(timeTaken);
        }        
        return stack.size();
    }
};

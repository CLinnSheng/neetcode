/*
tasks[i] - A to Z
Each CPU cycle allows the completion of a single task and tasks may be completed in any order.
Identical Tasks must be seperated by at least n CPU cycles, to cooldown the CPU.
Goal: Return the minimum number of CPU cycles required to complete all tasks.

Intuition:
The same task must wait n cycles.
But how can we handle it?
We need to process the task that appear the most first so that we can process other task while idleling
A hash map to keep track of the freq of each task
Then a heap so that we always do the task with the most freq
*/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        std::unordered_map<int, int> task_freq;
        for (const auto& task : tasks)
            task_freq[task]++;

        // a variable to keep track of time
        int time{};
        std::priority_queue<int, std::vector<int>, std::less<int>> maxHeap;
        for (const auto& [_, freq] : task_freq)
            maxHeap.emplace(freq);

        // a queue to store the idle task, so that we know when we can process it while it idleing
        std::deque<std::pair<int, int>> queue;
        
        while (!maxHeap.empty() || !queue.empty())
        {
            // Check whether it is done idleing or not
            if (!queue.empty() && time >= queue.front().second)
            {
                maxHeap.emplace(queue.front().first);
                queue.pop_front();
            } 

            if (!maxHeap.empty())
            {
                // Check got remaining task or not
                int afterFreq = maxHeap.top() - 1;
                maxHeap.pop();
                if (afterFreq > 0)
                {
                    queue.emplace_back(afterFreq, time + n + 1);
                }
            }
            time++;
        }
        return time;
    }
};

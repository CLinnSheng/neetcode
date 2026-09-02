#include <deque>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
using std::vector;
/*
 * Identical task must be seprated by at least n
 * Find the minimum number of cycle to complete all tasks
 * We always want to keep the CPU busy, and minimize the idle time as much as possible
 * We want to always do the task with the most freq first so while in between we can do other task
 * We can use a maxHeap to easily extract it. We also need to keep track of the next available time as well
 * And also use a queue to track task that is in cooldown
 * */

struct Comparator
{
    bool operator()(const std::pair<char, int> &A, const std::pair<char, int> &B)
    {
        return A.second < B.second;
    }
};
class Solution
{
  public:
    int leastInterval(vector<char> &tasks, int n)
    {
        std::unordered_map<char, int> freq;
        for (const char task : tasks)
        {
            freq[task]++;
        }

        // Stores all the available task
        std::priority_queue<std::pair<char, int>, vector<std::pair<char, int>>, Comparator> maxHeap;
        for (const auto &[task, f] : freq)
        {
            maxHeap.push({task, f});
        }

        // Keeping track of the time
        int time{1};
        // Stores all the tasks that is waiting and also the next available time
        std::deque<std::pair<char, int>> queue;

        while (!maxHeap.empty() || !queue.empty())
        {
            // Push all the waiting task back to ready task if the cooldown is past
            while (!queue.empty() && queue.front().second <= time)
            {
                maxHeap.push({queue.front().first, freq[queue.front().first]});
                queue.pop_front();
            }

            // Always process the most freq task
            // Get the task from the heap first and remember the queue only stores waiting task
            if (!maxHeap.empty())
            {
                auto currTask = maxHeap.top();
                maxHeap.pop();

                // Decrement the freq
                freq[currTask.first]--;

                // Push it into the waiting queue
                if (freq[currTask.first] != 0)
                {
                    if (n != 0)
                    {
                        queue.push_back({currTask.first, time + n + 1});
                    }
                    else
                    {
                        maxHeap.push({currTask.first, freq[currTask.first]});
                    }
                }

                time++;
            }
            else
            {
                // if no ready task, straight away jump to the next waiting task time
                time = queue.front().second;
            }
        }

        return time - 1;
    }
};

/*
Problem: We need to get the maximum element in each window.
Brute force is iterate through the array and check the maximum element. --> O(n^2)
How we can further optimize it?
The problem is how can we easily get the maximum element in each window. Achieve it in O(1)?
The most straight forward data structure is using a maxHeap we can easily access the top element but this will cause
the overall time compelxity to be O(nlgn)

Another O(n) approach is actually keeping a monotomic stack
where the stack is alwyas in decreasing order where the first element is always the largest.
We only pop it out whenever it is out of hte windopw
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        std::vector<int> ans;

        // O(nlgn)
        // std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::less<std::pair<int, int>>> maxHeap;
        // for (int right{}; right < nums.size(); right++)
        // {
        //     // We need the indices as well, so that we know does the maximum element is out of window or not
        //     maxHeap.push({nums[right], right});

        //     // Check window size
        //     if (right + 1 >= k)
        //     {
        //         // Check does the current maximum leement is out of the window or not
        //         while (maxHeap.top().second <= right - k)
        //             maxHeap.pop();

        //         ans.push_back(maxHeap.top().first);
        //     }
        // }

        int left{}, right{};
        int size = nums.size();
        // Store index
        std::deque<int> q;

        while (right < size)
        {
            // Push new element in to the deque, and for here we need to be smart
            // We can pop out the index before the current index and is smalelr than it because
            // we no longer need it in the future since the current index is larger
            while (!q.empty() && nums[right] >= nums[q.back()])
            {
                q.pop_back();
            }

            q.push_back(right);

            // Check window
            if (left > q.front())
            {
                q.pop_front();
            }

            if (right + 1 >= k)
            {
                ans.push_back(nums[q.front()]);
                left++;
            }

            right++;
        }
        return ans;
    }
};

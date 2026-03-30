/*
Sliding window of size k moving from left to right.
Can only see k numbers in the window.
Goal: Return the max sliding window.

Intuition:
The brute force will be checking the maximum elment everytime we move the window.
But this will be O(n^2), how can we optimize it to O(n)?
The place we need to work on will be checking the maximum element.
Is there any better way to get the maximum element in O(1)

Another way of getting the maximum element which is by using a maxHeap,
we can get it in O(1) but pushing into the heap will be O(lgn)

O(n) approach.
We need a vector or deque to store the indices of the num we iterate through
because we need the index of the maximum element of the current window
Ok so how do we store the index of maximum element, we only store the latest 1 which means
that are the rightest. if it is greater than the last one, just remove the previous 1 because
the current 1 will be in use in the future.
But what if the greatest element is in the first index? So we will still keep it in the deque and also push
the element into the deque and no need to replace it. We will pop the greatest element which is at the first index,
when it is out of bound
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        // O(nlgn)
        // std::priority_queue<std::pair<int, int>> maxHeap;
        // std::vector<int> ans;

        // for (int right{}; right < nums.size(); right++)
        // {
        //     maxHeap.push({nums[right], right});

        //     // When reach the sliding window of size 'k'
        //     if (right + 1 >= k)
        //     {
        //         // Handle when the maximum element is out of the window
        //         while (maxHeap.top().second <= right - k)
        //             maxHeap.pop();

        //         ans.emplace_back(maxHeap.top().first);
        //     }
        // }
        // return ans;

        // O(n)
        std::deque<int> deque;
        int left{}, right{};
        std::vector<int> ans;

        while (right < nums.size())
        {
            // Replace the old maximum element with newer index if larger
            while (!deque.empty() && nums[right] >= nums[deque.back()])
                deque.pop_back();

            deque.push_back(right);

            // Check left boundary of the window
            if (left > deque.front())
                deque.pop_front();

            if (right + 1 >= k)
            {
                ans.emplace_back(nums[deque.front()]);
                left++;
            }
            right++;
        }
        return ans;
    }
};

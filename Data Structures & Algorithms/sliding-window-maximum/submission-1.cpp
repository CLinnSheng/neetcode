class Solution {
public:
/*
Goal: Find the list that contains the maximum element in the window at each step
Intuition: Number of windows with maxiumum size k => (n - k) + 1
Have a deque to store the maximum number for the window and deque can be added or remove at the front and back
so is easier when we adjust the window to the right
*/
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        ios_base :: sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int n = nums.size();
        vector<int> ans(n - k + 1);
        // Store the index of the elements in the window and to track the maximum number in the window
        deque<int> q;

        // Pointer for the window
        int l = 0, r = 0;

        while (r < n) {
            
            while (!q.empty() && nums[r] > nums[q.back()])
                q.pop_back();
            
            q.emplace_back(r);

            // shifting window to the right and check and see whether the index of maximum element is still within the range of window or not
            if (l > q.front())
                q.pop_front();

            // To prevent element is inserted when the window is not size k
            if (r + 1 >= k)
                ans[l++] = nums[q.front()];
            
            r++;
        }

        return ans;
    }
};

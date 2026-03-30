class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans{};
        int n(heights.size());
        int left{}, right{n - 1};

        while (left < right)
        {
            int area = std::min(heights[left], heights[right]) * (right - left);

            ans = std::max(area, ans);

            if (heights[left] < heights[right])
                left++;
            else
                right--;
        }
        return ans;
    }
};

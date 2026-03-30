class Solution {
public:
// Intuition: Find the maximum area
// Direction: Need to maximize both the width and height
// Iterate through the array and try to update the maximum area every time
// Can use two pointer to find the maximum height

    int maxArea(vector<int>& heights) {
        
        ios_base :: sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int length = heights.size();
        int left = 0, right = length - 1;
        int maximum_area = INT_MIN;

        while (left < right){

            auto area = (right - left) * min(heights[right], heights[left]);
            maximum_area = max(maximum_area, area);

            (heights[right] > heights[left])? left++ : right--;

        }

        return maximum_area;
    
    }
};

#include <vector>
using std::vector;
/*
 * Return the maixmum amount of water in a container
 * We can just 2 pointer approach and chagne the pointer which has a lower height.
 * Because we need to find the maximum area
 * */

class Solution
{
  public:
    int maxArea(vector<int> &heights)
    {
        int n = heights.size();
        int left{}, right = n - 1;
        int maxArea{};

        while (left < right)
        {
            int area = (right - left) * std::min(heights[left], heights[right]);
            maxArea = std::max(area, maxArea);

            if (heights[left] > heights[right])
            {
                right--;
            }
            else
            {
                left++;
            }
        }

        return maxArea;
    }
};

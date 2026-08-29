#include <vector>
using std::vector;
/*
 * Water trap is depends on its wall from 2 side.
 * But one important thing is not just the 2 nearest wall, but instead the minimum of the maximum wall from each side
 * So we can do is we can have a an array that is left[i] which store the highest wall from the left hand side from 0 to
 * index i and the same from the right
 * */
class Solution
{
  public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        vector<int> left(n, 0), right(n, 0);

        for (int i{1}; i < n; i++)
        {
            left[i] = std::max(left[i - 1], height[i - 1]);
        }
        for (int i{n - 2}; i >= 0; i--)
        {
            right[i] = std::max(right[i + 1], height[i + 1]);
        }

        int ans{};

        for (int i{}; i < n; i++)
        {
            int min = std::min(left[i], right[i]);
            if (height[i] < min)
            {
                ans += min - height[i];
            }
        }
        return ans;
    }
};

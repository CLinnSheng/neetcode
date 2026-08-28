#include <algorithm>
#include <vector>
using std::vector;
/*
 * Remove the minimum number of interval to make it non overlapping.
 *
 * First the itnervals are not sorted, to make things easier we can sort the intervals
 * We can be greedy over here. When choosing which interval to remove, we always choose the interval with shortest span
 * so we can store more interval or less overlapping interval
 * So we need to always keep track of the prevEnd. When new start is smaller than prevEnd then onverlapping occur. Then
 * when which interval to remove, we choose the with shorter `end`
 * */
class Solution
{
  public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        if (n == 1)
        {
            return 0;
        }

        std::sort(intervals.begin(), intervals.end());
        int cnt{};
        int prevEnd = intervals[0][1];

        for (int index{1}; index < n; index++)
        {
            int start = intervals[index][0];
            int end = intervals[index][1];

            // check overlapping or not
            if (prevEnd <= start)
            {
                prevEnd = end;
            }
            else
            {
                // Prefer the 1 with shorter end so avoid overlapping
                prevEnd = std::min(prevEnd, end);
                cnt++;
            }
        }

        return cnt;
    }
};

#include <vector>
using std::vector;

/*
 * Goal: Insert a interval into the intervals
 *
 * Observation:
 * intervals are already sorted, so we can just simply iterate through
 * So we need to fidn the right place to insert it and handling overallping interval
 * So at what condition consider overlapping?
 * if end of old_interval is greater or equal to the start of new_interval
 * After inserting also need to handle the old interval after the new 1.
 * By checking whether the end of new_interval is it equal or greater than the start of old_interval
 *
 * So we just push all the event that happen before the new event first
 * Then only merging the new event with the old event that overlapping with it
 * */
class Solution
{
  public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> ans;
        int index{}, n = intervals.size();

        // Event happen before newInterval and no overlapping
        while (index < n && intervals[index][1] < newInterval[0])
        {
            ans.push_back(intervals[index]);

            index++;
        }

        // First overlapping event with the newInterval
        // Merge all the interval happen at here until not overlapping with new interval
        while (index < n && intervals[index][0] <= newInterval[1])
        {
            newInterval[0] = std::min(newInterval[0], intervals[index][0]);
            newInterval[1] = std::max(newInterval[1], intervals[index][1]);

            index++;
        }

        ans.push_back(newInterval);

        while (index < n)
        {
            ans.push_back(intervals[index]);
            index++;
        }

        return ans;
    }
};

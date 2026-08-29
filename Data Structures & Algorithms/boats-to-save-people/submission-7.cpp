#include <algorithm>
#include <vector>
using std::vector;
/*
 * Find the minimum number of boats to carry every person
 * Each boat can load 2 ppl at max at one time.
 * SO we need to find a way to efficiently organize it such that we use minimum boat.
 * So what we can do is always try to fit the current lightest and heaviest person together in 1 boat if possible
 * otherwise let the heavy person use one boat
 * To make thing easier we can presort it
 * */
class Solution
{
  public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        std::sort(people.begin(), people.end());
        int left{}, right = people.size() - 1;
        int cnt{};

        while (left <= right)
        {
            int weight = people[left] + people[right];
            if (weight <= limit)
            {
                left++;
                right--;
            }
            else
            {
                right--;
            }

            cnt++;
        }

        return cnt;
    }
};

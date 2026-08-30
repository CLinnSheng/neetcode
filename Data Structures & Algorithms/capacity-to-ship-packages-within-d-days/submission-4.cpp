#include <algorithm>
#include <numeric>
#include <vector>
using std::vector;
/*
 * Find the least weight capacity of ship that can shipped within days
 * Notice one thing the question is asking us to find a range where it met the conditions
 * So the range will just simply be the weight of the ship
 * Maximum weight will just simply be the sum of all the weights where we can finish it in 1 day.
 * The minimum will just simply be the maximum weight in the conveyer Belt
 * */
class Solution
{
    int shippable(const std::vector<int> &weights, int shipCapacity, int days)
    {
        int day{1}, currWeight{};

        for (const int weight : weights)
        {
            currWeight += weight;
            if (currWeight > shipCapacity)
            {
                currWeight = weight;
                day++;
            }
        }

        return day <= days;
    }

  public:
    int shipWithinDays(vector<int> &weights, int days)
    {
        int left = *std::max_element(weights.begin(), weights.end());
        int right = std::accumulate(weights.begin(), weights.end(), 0);

        if (days == 1)
        {
            return right;
        }

        while (left < right)
        {
            int mid = left + (right - left) / 2;

            if (shippable(weights, mid, days))
            {
                // Try to find smaller capacity ship
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }

        return left;
    }
};

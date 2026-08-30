#include <algorithm>
#include <cmath>
#include <vector>
using std::vector;
/*
 * Finding the minimum integer k such that can eat all bananas within h hours.
 * Ok finding minimum in a range where we can statisfy the condition --> Binary Search
 * Then we need to find the range first
 * So our range will be the `k` which is the rates
 * The worst rate will just simply the maximum amount of bananas in 1 pile
 * */
class Solution
{
    int helper(int bananas, int rate)
    {
        if (bananas % rate)
        {
            return bananas / rate + 1;
        }

        return bananas / rate;
    }

  public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int right = *std::max_element(piles.begin(), piles.end()); // MaxRate
        int left = 1;                                              // MinRate

        // Base Case
        if (h == piles.size())
        {
            return right;
        }

        // Search from the possible rate range
        while (left < right)
        {
            int rate = left + (right - left) / 2;

            int timeTaken{};
            for (const auto pile : piles)
            {
                timeTaken += helper(pile, rate);
            }

            // Finding the minimum rate
            if (timeTaken > h)
            {
                // We need to try higher rate
                left = rate + 1;
            }
            else
            {
                // Within h can try lower rate
                right = rate;
            }
        }

        return left;
    }
};

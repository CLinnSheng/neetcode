#include <algorithm>
#include <cmath>
#include <vector>
class Solution
{
public:
    int minEatingSpeed(std::vector<int>& piles, int h)
    {
        int min{1}, max{*std::max_element(piles.begin(), piles.end())};

        while (min <= max)
        {
            int rate = (min + (max - min) / 2.0);
            int time{};

            for (const auto& pile : piles)
                time += std::ceil(pile / double(rate));

            if (time > h)
            {
                min = rate + 1;
            }
            else
            {
                max = rate - 1;
            }
        }
        return min;
    }
};

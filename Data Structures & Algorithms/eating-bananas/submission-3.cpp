/*
piles[i] - number of bananas in the ith pile
h - the number of hours have to eat all the bananas
Decide my own banansa per hour eating rate, k. Each hour cna choose a pile of bananas and eats
k banans from that pile. Cannot eat from another pile in the same hour if finish eating

Goal: Return the minimum integer, k.

Intuition:
THe possible eating rate will be from 1 to maximum size of piles.
Ok from here we see a range, then instead of trying from 1 to N. We can actually use
binary search which cna be done in O(lgn)
*/
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int left{1}, right{*max_element(piles.begin(), piles.end())};

        while (left <= right)
        {
            int middle(left + (right - left) / 2);
            int time{};

            for (const auto& pile : piles)
                time += std::ceil(pile / double(middle));

            if (time > h)
                left = middle + 1;
            else
                right = middle - 1;
        }
        return left;
    }
};

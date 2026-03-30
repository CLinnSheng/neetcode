/*
ith package on the conveyor belt has a weight of weights[i]
Each day, load the ship with pacakges. It is not allowed to load weight more than maximum
weight capcity of the ship.

Goal: Return the least weight capacity that will result in all pcakages on the conveyor belt
shipped withn 'days' days.

Intuition:
the maximum weight capcity is the sum of weights in which we can settle it in 1 day.
but the question is asking for within days what is the least weight capacity.
From here we can see there is a range for the weight capcity, and also the condition of chanigng the weight capcity.
So if the current weight capacity can be done withn the 'days', we can try a lower value of weight capcity.
We can use binary search
TIme COmplexity: O(nlgn)
*/
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) 
    {
        auto helper = [&](const int& capacity)
        {
            int currCapacity{capacity};
            int day{1};

            for (const auto& weight : weights)
            {
                // curr weight cannot be done in tdy, move on to next day
                if (currCapacity - weight < 0)
                {
                    currCapacity = capacity;
                    day++;
                }

                currCapacity -= weight;
            }

            return day <= days;
        };

        int left{*std::max_element(weights.begin(), weights.end())}, right {std::accumulate(weights.begin(), weights.end(), 0)};   
    int ans{INT_MAX};

        while (left <= right)
        {
            int middle(left + (right - left) / 2);

            if (helper(middle))
            {                
                right = middle - 1;
                ans = std::min(ans, middle);
            }            else
                left = middle + 1;
        }
        
        return ans;
    }
};
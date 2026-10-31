#include <numeric>
#include <vector>
/*
 * Find the starting index where we can travel around and come back to that index
 * gas[i] -> amount of gas at ith station
 * cost[i] -> amount of gas needed to travel from i to i + 1
 *
 * Brute force way will be trying to start from each index and check whether we can come back to the original index or
 * not O(n^2)
 *
 * How can we further optimize it to do it in one pass instead of double loop?
 * */

class Solution
{
  public:
    int canCompleteCircuit(std::vector<int> &gas, std::vector<int> &cost)
    {
        // Base Case
        // Total Gas must be at least cost
        int ttlGas = std::accumulate(gas.begin(), gas.end(), 0), ttlCost = std::accumulate(cost.begin(), cost.end(), 0);

        if (ttlGas < ttlCost)
        {
            return -1;
        }

        // We can just iterate through the array and keep tracking of our current balance
        // And when it goes to negative we just simply start from a new index
        // We can observe it from the brute force solution. Lets say we start from index 0 and stops at index 3
        // Each tried of starting index of 1 and 2 also stop at index 3. So we can safely to skip trying index 1 and 2
        int balance{}, start{};
        for (int index{start}; index < gas.size(); index++)
        {
            balance += gas[index];
            balance -= cost[index];

            if (balance < 0)
            {
                balance = 0;
                start = index + 1;
            }
        }

        return start;
    }
};

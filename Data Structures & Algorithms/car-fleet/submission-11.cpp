#include <algorithm>
#include <stack>
#include <unordered_map>
#include <vector>
using std::vector;
/*
 * Car can not pass another car ahead of it, can only catch so then end up with the same speed
 * Car fleet is group of car driving at the same position and same speed.
 * Position is no sorted, so we need to sort it first. We need to iterate through the position from the least position.
 * Then calculate the time taken for each car to reach the target.
 * The stack will just simply store the car fleet.
 * So if car that start later taken more time then the previous time, so it will form a car fleet
 * */
class Solution
{
  public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        // Track the original index
        std::unordered_map<int, int> index;
        for (int i{}; i < position.size(); i++)
        {
            index[position[i]] = i;
        }

        std::sort(position.begin(), position.end());
        std::stack<float> st;

        for (const int p : position)
        {
            int _speed = speed[index[p]];
            float timeTaken = (target - p) / float(_speed);

            while (!st.empty() && st.top() <= timeTaken)
            {
                st.pop();
            }

            st.push(timeTaken);
        }

        return st.size();
    }
};

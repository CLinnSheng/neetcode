/*
We can have unlimimted number of boat
And then we can simply pick any 2 person, not in order.
Since not in order, we can sort --> this make choosing people more easy
We can have 2 pointer and each boat can carry at most 2 person
To be smart on minimize the number of boats, we always try to place the heaveier person
*/
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) 
    {
        int size(people.size());
        int ans{}, left{}, right(size - 1);
        int currWeight{};

        std::sort(people.begin(), people.end());

        while (left <= right)
        {
            int remaining_weight = limit - people[right];
            right--;
            ans++;

            // See whether we can palce 1 more people, take from the least weight
            if (left <= right && remaining_weight >= people[left])
            {
                left++;
            }
        }
        return ans;    
    }
};
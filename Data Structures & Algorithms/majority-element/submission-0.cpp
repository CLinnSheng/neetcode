class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Booyer Moore Voting Algo
        int element{}, cnt{};

        for (int i{}; i < nums.size(); i++)
        {
            if (cnt == 0)
            {
                element = nums[i];
                cnt++;
            }
            else if (nums[i] != element)
            {
                cnt--;
            }
            else 
            {
                cnt++;
            }
        }
        return element;
    }
};
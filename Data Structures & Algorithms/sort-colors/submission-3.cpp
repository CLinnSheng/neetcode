class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int size = nums.size();

        // Index of the color of the next element should be
        int red{}, white{}, blue{size - 1};

        while (white <= blue)
        {
            int val = nums[white];

            // If red, then swap with the current index
            if (val == 0)
            {
                // The color of the red index should be white
                std::swap(nums[red], nums[white]);
                red++;
                white++;
            }
            else if (val == 2)
            {
                std::swap(nums[white], nums[blue]);
                blue--;
            }
            else
            {
                white++;
            }
        }   
    }
};
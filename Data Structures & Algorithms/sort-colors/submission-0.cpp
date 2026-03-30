/*
 * Easiest way is to count the number of color of each ball
 * But this will take space complexity of O(n)
 * To optimize it to O(1) can use pointer to tell where should i insert my next blue or red,
 * as we have 3 pointer for each color, but we only need to move the white pointer because is in the middle
 */
class Solution 
{
public:
    void sortColors(vector<int>& nums) 
    {
        int red{}, white{}, blue{};

        for (const auto& num : nums)
            if (num == 0)
                red++;
            else if (num == 1)
                white++;
            else
                blue++;

        int index{};

        while (red)
        {
            nums[index++] = 0;
            red--;
        }      
    
        while (white)
        {
            nums[index++] = 1;
            white--;
        }      
    
        while (blue)
        {
            nums[index++] = 2;
            blue--;
        }      
    }
};
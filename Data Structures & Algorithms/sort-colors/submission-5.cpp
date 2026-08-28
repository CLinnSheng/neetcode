#include <vector>
using std::vector;
/*
 * We can use 3 pointer where each pointer simply means the index where the colors boundary at.
 * for instance red_ptr = i. So the last red end at i - 1
 * */
class Solution
{
  public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int red{}, white{}, blue{n - 1};

        while (white <= blue)
        {
            // Red
            if (nums[white] == 0)
            {
                int temp = nums[red];
                nums[red] = nums[white];
                nums[white] = temp;

                white++;
                red++;
            }
            // White
            else if (nums[white] == 1)
            {
                white++;
            }
            // Blue
            else
            {
                int temp = nums[blue];
                nums[blue] = nums[white];
                nums[white] = temp;

                blue--;
            }
        }
    }
};

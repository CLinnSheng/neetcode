#include <vector>

/*
 * Goal: Rotate the array to the right by k steps where k is non negative
 *
 * IntuitioN:
 * The array is rotated to the right.
 * k can be any numbers of from [0, 100000]
 * So instead of looping k we can at most actually rotate the array by n - 1
 * */
class Solution
{
  public:
    void rotate(std::vector<int> &nums, int k)
    {
        int n(nums.size());

        // finding out the true k
        k %= n;
        std::vector<int> temp(nums.begin(), nums.end());

        for (int i{}; i < n; i++)
            temp[(i + k) % n] = nums[i];

        for (int i{}; i < n; i++)
            nums[i] = temp[i];
    }
};

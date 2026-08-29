#include <algorithm>
#include <vector>
using std::vector;
/*
 * Rotate teh array to the right, just simply use modolu
 * This will take O(n) in both time and space complexity.
 * Can we achieve it in O(1) without using any extra space.
 * Observation from the rotation. The last k eleemtn will be in the front after rotating.
 * So what we can do is reverse the whole array first. and then now the last k element is at the front but is in inverse
 * Then we rotate the first k element and the last n - k element
 * Another thing to take care of is k can be larger the total size, so we can just mod i
 * */
class Solution
{
  public:
    void rotate(vector<int> &nums, int k)
    {
        k = k % nums.size();
        std::reverse(nums.begin(), nums.end());
        std::reverse(nums.begin(), nums.begin() + k);
        std::reverse(nums.begin() + k, nums.end());
    }
};

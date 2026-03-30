/*
Given the array is sorted, 2 integers k & x.
An integer a is closer to x than an integer b if:
i. |a-x| < |b-x| or
ii. |a-x| == |b-x| and a < b
Goal: Return the k closest integers to x in the array. 
The result should be sorted in ascending order

Intuition:
One key thing is the array is sorted, how can we make use of this?
Since is closest so the answer will be a contiguous subarray
So we can have 2 pointer on both end then move the pointer with greater difference
until the window is K
Time Complexity: O(n)
*/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        int left{}, right(arr.size() - 1);

        while (right - left >= k)
        {
            if (std::abs(arr[right] - x) > std::abs(arr[left] - x))
                right--;
            else if (std::abs(arr[right] - x) < std::abs(arr[left] - x))
                left++;
            else
                right--;
        }
        return std::vector<int>(arr.begin() + left, arr.begin() + right + 1);
    }
};
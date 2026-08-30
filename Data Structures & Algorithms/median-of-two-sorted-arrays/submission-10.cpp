class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       // Do it in O(lgmn) 
       // Means need to leverage its property of being sorted and perform binary search on both array
       // Find the median we need to know the middle. How can we do it without merging?
       // What we can do is trying to half the element in nums1 and nums2. In other word try to find the parition in nums1 and nums2
       // We only do the binary search on the smaller array

        if (nums1.size() > nums2.size())
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        int ttlSize = nums1.size() + nums2.size();
        int half = (ttlSize + 1) / 2;

        int left{}, right = nums1.size();
        while (left <= right)
        {
            // Finding the midpoint
            // Total elemetns from nums1 at i or before + nums2 at j or before equal to half
            int i = (left + right) / 2;
            int j = half - i;

            int left_a = i > 0? nums1[i - 1] : INT_MIN;
            int right_a = i < nums1.size()? nums1[i] : INT_MAX;
            int left_b = j > 0? nums2[j - 1] : INT_MIN;
            int right_b = j < nums2.size()? nums2[j] : INT_MAX;

            // Check boundary
            if (left_a <= right_b && left_b <= right_a)
            {
                if ((nums1.size() + nums2.size()) % 2)
                {
                    return std::max(left_a, left_b);
                }
                return (std::max(left_a, left_b) + std::min(right_a, right_b)) / 2.0;
            }
            else if (left_a > right_b)
            {
                right = i - 1;
            }
            else 
            {
                left = i + 1;
            }
        }

        return -1;
    }
};

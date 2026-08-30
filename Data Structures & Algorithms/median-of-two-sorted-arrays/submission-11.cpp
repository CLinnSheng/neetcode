class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
// 1. Target Time Complexity: O(log(min(m, n)))
//    - Binary search on the smaller array only (nums1) to choose partition i.
//    - The partition j in nums2 is fixed automatically: j = (total_size + 1) / 2 - i.

// 2. Partition Concept:
//    - Partition i cuts nums1:
//        - Left partition contains i elements: indices 0 to i - 1 (max element is nums1[i - 1]).
//        - Right partition starts at index i (min element is nums1[i]).
//    - Partition j cuts nums2:
//        - Left partition contains j elements: indices 0 to j - 1 (max element is nums2[j - 1]).
//        - Right partition starts at index j (min element is nums2[j]).
// So everything before i and j is belongs to the left half
// 3. Condition for Valid Median Split:
//    - nums1[i - 1] <= nums2[j] (left_a <= right_b)
//    - nums2[j - 1] <= nums1[i] (left_b <= right_a)

        if (nums1.size() > nums2.size())
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        int ttlSize = nums1.size() + nums2.size();
        int half = (ttlSize + 1) / 2;

        int left{}, right = nums1.size();
        while (left <= right)
        {
            // Finding the partition point in both array
            // Only perform binary saerch on the shorter array
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
                // Less elemetn in nums1
                right = i - 1;
            }
            else 
            {
                // More elements in nums1
                left = i + 1;
            }
        }

        return -1;
    }
};

/*
Goal: Find the median of 2 sorted arrays.

Intuition:
the 2 arrays are sorted. the easiest way actually is just merge the 2 arrays in sorted order and find the median
This will be O(m + n)
Can we make use of the property of where the arrays are already sorted.
Since sorted then will be using binary search.
Ok first how can we find the partition into left n right?
How do we know how many element we need to use in both array?
We can make use of the properties where the arrays are sorted.
So we can perform binary in the shorter array to get the number of elements it needed from the array
to form the left partition.
Then from the other array just simply minus from half of the total size.
So how do we determine how many elements to use from the shorter array.
Ok first we dont really need to know how to form the right partition. We jus need to make sure
the most right element in the left partition is smaller than the most left from the right partition
First Checking we need to make sure the most right element is lesser than the most left element from the right partiion of the other array.
Time Complexity: O(lg(m + n))
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Assume nums1 is the smaller array
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int n1(nums1.size()), n2(nums2.size());

        int totalSize(n1 + n2);
        int half((totalSize + 1) / 2);

        int left{}, right(n1); // For the binary search in nums1

        while (true)
        {
            int i((left + right) / 2); // nums1
            int j(half - i); // nums2

            // Get the boundary elements
            int leftA = (i > 0) ? nums1[i - 1] : INT_MIN;
            int rightA = (i < n1) ? nums1[i] : INT_MAX;
            int leftB = (j > 0) ? nums2[j - 1] : INT_MIN;
            int rightB = (j < n2) ? nums2[j] : INT_MAX;


            // Checking
            if (leftA <= rightB && leftB <= rightA)
            {
                // Odd
                if (totalSize % 2)
                    return std::max(leftA, leftB);

                // Even
                return (std::max(leftA, leftB) + std::min(rightA, rightB)) / 2.0;
            }
            else
            {
                // Binary Search
                if (leftA > rightB) // Too much element from the first array
                    right = i - 1;
                else // Too less element from the first array
                    left = i + 1;
            }
        }

        return -1;
    }
};

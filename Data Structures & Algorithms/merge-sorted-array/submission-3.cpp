/*
Constraint: Must be modify nums1 in-place
Things to take care of is the vec can be empty
Start from the left? --> where do we need to place the replace element?
How about start from the right? we do need to worry about the current element because we will just keep the pointing there
all we need to move is the pointer where we need to palce in the merged array
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ptr1{m - 1}, ptr2{n - 1}, mergedPtr{m + n - 1};

        while (mergedPtr >= 0)
        {
            // Need to take care of edge cases where vector might be empty
            if (ptr1 >= 0 && ptr2>=0)
            {
                if (nums1[ptr1] > nums2[ptr2])
                {
                    nums1[mergedPtr] = nums1[ptr1];
                    ptr1--;
                }
                else
                {
                    nums1[mergedPtr] = nums2[ptr2];
                    ptr2--;
                }
            }
            else
            {
                if (ptr1 >= 0)
                {
                    nums1[mergedPtr] = nums1[ptr1];
                    ptr1--;
                }
                else
                {
                    nums1[mergedPtr] = nums2[ptr2];
                    ptr2--;
                }
            }
            mergedPtr--;
        }
    }
};
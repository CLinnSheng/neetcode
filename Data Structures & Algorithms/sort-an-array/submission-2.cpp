class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // Merge Sort
        // Keep Splitting then Merge
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void mergeSort(std::vector<int>& nums, int left, int right)
    {
        if (left >= right)
        {
            return;
        }

        int middle = (left + right) / 2;

        // Split Into 2
        mergeSort(nums, left, middle);
        mergeSort(nums, middle + 1, right);

        // Merge
        merge(nums, left, middle, right);
    }

    void merge(std::vector<int>& nums, int left, int middle, int right)
    {
        std::vector<int> temp;
        
        // The array is sorted in half
        // [left, middle) & [middle, right]
        int i = left, j = middle + 1;

        while (i <= middle && j <= right)
        {
            if (nums[i] < nums[j])
            {
                temp.push_back(nums[i++]);
            }
            else
            {
                temp.push_back(nums[j++]);
            }
        }

        while (i <= middle)
        {
            temp.push_back(nums[i++]);
        }


        while (j <= right)
        {
            temp.push_back(nums[j++]);
        }

        // Replace with the sorted value
        for (int i = left; i <= right; i++)
        {
            nums[i] = temp[i - left];
        }
    }
};
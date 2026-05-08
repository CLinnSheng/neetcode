class Solution {
public:
    int mySqrt(int x) 
    {
        // Possible Number in the range of [1, x]
        int left{}, right{x};
        int ans{};

        // Need to consider this number as well
        while (left <= right)    
        {
            long long middle = left + (right - left) / 2;
            long long val = middle * middle;

            if (val == x)
            {
                return middle;
            }
            else if (val > x)
            {
                right = middle - 1;
            }
            else
            {
                // Store it overhere to find the next possible larger value
                ans = middle;
                left = middle + 1;
            }
        }

        return ans;
    }
};
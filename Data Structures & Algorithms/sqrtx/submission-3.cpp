class Solution {
public:
    int mySqrt(int x) {
        int left{}, right{x};
        int res{};

        while (left <= right)
        {
            int middle(left + (right - left)/2);

            if ((long long)middle * middle == x)
                return middle;
            else if ((long long)middle * middle > x)
                right = middle - 1;
            else
            {
                left = middle + 1;
                res = middle;
            }
        }
        return res;
    }
};
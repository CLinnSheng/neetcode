class Solution {
public:
    int climbStairs(int n) {
        if (n == 1)
        {
            return 1;
        }
        if (n == 2)
        {
            return 2;
        }
        
        int first = 1, second = 2;
        int sum{};
        // For n >= 3 is just basically the sum of n - 1 + n - 2
        for (int i{3}; i <= n; i++)
        {
            sum = first + second;
            first = second;
            second = sum;
        }

        return sum;
    }
};

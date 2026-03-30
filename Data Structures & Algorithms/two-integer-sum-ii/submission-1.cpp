class Solution {
public:
// numbers --> ascending order
// Intuition: Need to find the index of two elements sum up equal to target
// Constraint: Value1 < Value2
// We can implement binary search algo by using two pointers

    vector<int> twoSum(vector<int>& numbers, int target) {
        
        ios_base :: sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int left = 0, right = numbers.size() - 1;

        while (left < right){

            int sum = numbers[left] + numbers[right];

            if (sum > target)   right--;
            else if (sum < target)   left++;
            else    break;

        }

        return {left + 1, right + 1};

    }
    
};

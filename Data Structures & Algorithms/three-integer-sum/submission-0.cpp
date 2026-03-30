class Solution {
public:
// Intuition: Need to find 3 elements that sums up equal to 0
// Constraint no duplicate triplets where the order doesnot matter
// We can iterate the arrays by fixing 1 element and perform two pointer on the other 2 elements
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        ios_base :: sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        int size = nums.size();

        for (int i = 0; i < size; i++){

            // becuase we sorted the array already
            // so is impossible to form sum equal to 0
            if (nums[i] > 0)    break;

            // we skip the duplicate elements so that wont produce the same triplet
            if (i > 0 && nums[i] == nums[i - 1])    continue;

            int l = i + 1, r = size - 1;

            while (l < r){

                auto sum = nums[i] + nums[l] + nums[r];

                if (sum < 0)    l++;
                else if (sum > 0)    r--;
                else{
                    
                    ans.push_back({nums[i], nums[l], nums[r]});
                    // because it might contain other combination
                    l++; r--;    

                    while (l < r && nums[l] == nums[l - 1])
                        l++;
                        
                }
            }
        }

        return ans;
    }

};
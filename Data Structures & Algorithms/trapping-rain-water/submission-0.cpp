class Solution {
public:
// Intuition: Find the total trapped water
// Direction: For every index of the height array, we need to find
// Maximum height from the left and the right
// And then take the minimum height and minus with height[i]
// if < 0 means no rain water trapped

    int trap(vector<int>& height) {

        ios_base :: sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int left = 0, right = height.size() - 1;
        int leftMax = height[left], rightMax = height[right];
        int ttl_water = 0;

        while (left < right){

            if (leftMax < rightMax){
                leftMax = max(leftMax, height[++left]);
                ttl_water += leftMax - height[left];
            }
            
            else{
                rightMax = max(rightMax, height[--right]);
                ttl_water += rightMax - height[right];
            }

        } 

        return ttl_water;

    }
};

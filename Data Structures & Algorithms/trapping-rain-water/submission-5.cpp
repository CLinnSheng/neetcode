/*
The only way we can determine the height of water trap is by getting the height of the surrounding block
So, we need the surrounding block height information for each index.
But one thing to take note is not directly the adjacent block, but rather the maximum height from its left and right.
So we need the greater left & right for each index. Brute force wil just simply find out the maximum left and right.
This will elad to O(n^2). To optimize it we can use maximum prefix and suffix and reduce to O(n).

Another approach is using 2 pointer
Therefore, here we can use 2 pointer and the decision to move which pointer is base on the maxHeight from
the left and right
*/
class Solution {
public:
    int trap(vector<int>& height) 
    {
        // Approach 1:
        int size = height.size();
        int water{};
        std::vector<int> maxPrefix(size, 0), maxSuffix(size, 0);
        
        for (int i{1}; i < size; i++)
        {
            maxPrefix[i] = std::max(maxPrefix[i - 1], height[i - 1]);
            maxSuffix[size - i - 1] = std::max(maxSuffix[size - i], height[size - i]);
        }

        for (int i{}; i < size; i++)
        {
            int surrHeight = std::min(maxPrefix[i], maxSuffix[i]);
            water += max(0, surrHeight - height[i]);
        }
        return water;
    }
};

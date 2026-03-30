#include <bits/stdc++.h>
#include <climits>
#include <ios>
#include <unordered_set>

/*
Goal: Find the longest consecutive sequence in the array
Eg: [100, 4, 200, 1, 3, 2]
Intuition: Store all the elements in a set
Then try to find the first eleemtn of the sequence in the array and try to find the whole sequence
the reason the find the first element is because we can reduct the time complexity
Time Complexity is O(n)
*/
class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        
        std::unordered_set<int> s;
        
        for (const auto& num : nums)
            s.insert(num);
            
        int max_len = 0;
        
        for (const auto& num : nums) {
            int cnt = 1;
            
            // first element
            if (s.count(num - 1) == 0) {
                int temp = num;
                while (s.count(++temp))
                    cnt++;
            }        
            max_len = std::max(cnt, max_len);
        }
        
        return max_len;
    }
};
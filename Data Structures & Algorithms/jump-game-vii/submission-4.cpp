#include <deque>
#include <string>
#include <string_view>
#include <vector>
/*
 * Each move we can take from i + minJump <= j <= min(i + maxJump, n - 1)
 * The brute force way will just try to move every single possible jump in each index that we land
 * This will take O(2^n)
 * We can improve it by caching because some subproblem is solved multiple times
 * cache[i] means we can reach the final index from index i
 * Time Complexity: O(n)
 *
 *  Another approach is actually using BFS, if we observe from the brute force approach is kinda like a BFS,
 *  as each round we will try to jump from the min range to the max range, then we continue repeat to the index we
 * jumped to
 * We need to have a variable that track the farthest so we dont keep inserting the same index into the queue
 * Time Complexity: O(n)
 * */
class Solution
{
  public:
    // bool canReach(std::string s, int minJump, int maxJump)
    // {
    //     std::vector<int> cache(s.length(), -1);
    //     return dfs(s, 0, minJump, maxJump, cache);
    // }
    //
    // int dfs(std::string_view s, int index, int minJump, int maxJump, std::vector<int> &cache)
    // {
    //     if (index == s.length() - 1)
    //     {
    //         return cache[index] = 1;
    //     }
    //
    //     if (cache[index] != -1)
    //     {
    //         return cache[index];
    //     }
    //
    //     for (int i{index + minJump}; i <= std::min(index + maxJump, (int)s.length() - 1); i++)
    //     {
    //         if (s[i] == '0' && dfs(s, i, minJump, maxJump, cache))
    //         {
    //             return cache[i] = 1;
    //         }
    //     }
    //
    //     if (cache[index] == -1)
    //     {
    //         cache[index] = 0;
    //     }
    //
    //     return cache[index];
    // }
    //

    bool canReach(std::string s, int minJump, int maxJump)
    {
        int n = s.length();

        // Base Case
        if (s[n - 1] != '0' || s[0] != '0')
        {
            return false;
        }

        // Largest index whose reachability has been discovered
        int farthest{};
        std::deque<int> queue;
        queue.push_back(0);

        while (!queue.empty())
        {
            int currIndex = queue.front();
            queue.pop_front();

            if (currIndex == n - 1)
            {
                return true;
            }

            int start = std::max(currIndex + minJump, farthest);
            int end = std::min(currIndex + maxJump, n - 1);

            for (int index{start}; index <= end; index++)
            {
                if (s[index] == '0')
                {
                    queue.push_back(index);
                }
            }

            farthest = std::max(end + 1, farthest);
        }

        return false;
    }
};

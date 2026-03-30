/*
Important Obeservation: Arr is sorted and result must be sorted as well
Can store into a minHeap --> O(nlgn)

Another smarter way is using 2 pointer, because we know the k elements will be consecutive
so all we just need to shrink the window until k size
*/
struct Comparator
{
    bool operator()(const std::pair<int, int>& A, const std::pair<int, int>& B)
    {
        if (A.first == B.first)
        {
            return A.second > B.second;
        }
        return A.first > B.first;
    }
};
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        // std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Comparator> minHeap;
        // for (int i{}; i < arr.size(); i++)
        // {
        //     minHeap.push(std::make_pair(std::abs(arr[i] - x), arr[i]));
        // }

        // std::vector<int> ans;
        // while (k)
        // {
        //     ans.push_back(minHeap.top().second);
        //     minHeap.pop();
        //     k--;
        // }

        // std::sort(ans.begin(), ans.end());
        // return ans;
        int size = arr.size();
        int left{}, right{size - 1};

        // Loop until we reach k size
        while (right - left >= k)
        {
            // Shrink from the size which has larger diff
            int left_diff = std::abs(arr[left] - x);
            int right_diff = std::abs(arr[right] - x);

            if (left_diff > right_diff)
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        // No need to sort because the original array is sorted
        return std::vector<int>(arr.begin() + left, arr.begin() + right + 1);
    }
};
/*
Important Obeservation: Arr is sorted and result must be sorted as well
Can store into a minHeap --> O(nlgn)
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
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Comparator> minHeap;
        for (int i{}; i < arr.size(); i++)
        {
            minHeap.push(std::make_pair(std::abs(arr[i] - x), arr[i]));
        }

        std::vector<int> ans;
        while (k)
        {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
            k--;
        }

        std::sort(ans.begin(), ans.end());
        return ans;
    }
};
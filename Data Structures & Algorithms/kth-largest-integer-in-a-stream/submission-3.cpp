class KthLargest {
private:
    std::priority_queue<int, std::vector<int>, std::less<int>> maxHeap{};
    int k;
public:
    KthLargest(int k, vector<int>& nums) : k{k}
    {
        for (const auto& num : nums)
            maxHeap.emplace(num);
    }
    
    int add(int val) 
    {
        maxHeap.emplace(val);
        std::priority_queue<int, std::vector<int>, std::less<int>> tempHeap(maxHeap);
        int temp{k - 1};

        while (temp > 0)
        {
            tempHeap.pop();
            temp--;
        }

        return tempHeap.top();
    }
};

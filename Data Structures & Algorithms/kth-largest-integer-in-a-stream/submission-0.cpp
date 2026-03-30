class KthLargest {

// Intuition: Need to find the k largest element in a array
// We only adding new element to the list
// We can solve it by using a heap (O(n) for iterating through the array)
// Get the k largest element by using pop O(1)

// we will be using min_heap as the top will be smallest element
// The reason is that we can pop until the min_heap is size in k
// Therefor the top element will be the kth largest element
priority_queue<int, vector<int>, greater<int>> min_heap;
int size;

public:
    KthLargest(int k, vector<int>& nums) : size(k) {
        for (auto &num : nums) // O(N)
            min_heap.push(num);
    }
    
    int add(int val) {
        min_heap.push(val);

        while (min_heap.size() > size)
            min_heap.pop();

        return min_heap.top();
    }
};

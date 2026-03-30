class MedianFinder {
public:
    std::priority_queue<int> left_half;
    std::priority_queue<int, std::vector<int>, std::greater<>> right_half;

    MedianFinder() {}
    
    void addNum(int num) {
        if (left_half.empty()) {
            left_half.emplace(num);
            return;
        }

        left_half.emplace(num);
        if (!left_half.empty() && !right_half.empty() && left_half.top() > right_half.top()) {
            right_half.emplace(left_half.top());
            left_half.pop();
        }

        if (left_half.size() > right_half.size() + 1) {
            right_half.emplace(left_half.top());
            left_half.pop();
        }
        if (right_half.size() > left_half.size() + 1) {
            left_half.emplace(right_half.top());
            right_half.pop();
        }
    }
    
    double findMedian() {
        return (left_half.size() + right_half.size()) % 2? (left_half.size() > right_half.size()? left_half.top() : right_half.top()) : (left_half.top() + right_half.top()) / (double)2;
    }
};

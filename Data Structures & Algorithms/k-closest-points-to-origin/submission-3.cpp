/*
points[i] = [xi, yi]
Goal: Return the k closest points to the origin [0, 0]

Intuition:
Since the question mentioning "k closest point"
the first thought will be using a priority queue because we can easily get access to the min and max
*/
class Solution {
private:
    struct comparator
    {
        bool operator()(const std::pair<int, std::vector<int>>& A, const std::pair<int, std::vector<int>>& B)        
        {
            return A.first > B.first;
        }
    };
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        std::priority_queue<std::pair<int, std::vector<int>>, std::vector<std::pair<int, std::vector<int>>>, comparator> minHeap;
        for (const auto& point : points)
        {
            int distance = point[0] * point[0] + point[1] * point[1];
            minHeap.emplace(distance, point);
        }

        std::vector<std::vector<int>> answer;
        while (k)
        {
            answer.emplace_back(minHeap.top().second);
            minHeap.pop();
            k--;
        }

        return answer;
    }
};

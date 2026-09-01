#include <cmath>
#include <queue>
#include <utility>
#include <vector>
using std::vector;

/*
 * Return the answer in any order but find the k closeest points to the origin
 * */

struct Comparator
{
    bool operator()(const std::pair<vector<int>, double> &A, const std::pair<vector<int>, double> &B)
    {
        return A.second > B.second;
    }
};
class Solution
{
  private:
    double euclDist(const vector<int> &point)
    {
        return sqrt(pow(point[0], 2) + pow(point[1], 2));
    }

  public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        // minHeap
        std::priority_queue<std::pair<vector<int>, double>, vector<std::pair<vector<int>, double>>, Comparator> minHeap;
        for (const auto &point : points)
        {
            minHeap.push({point, euclDist(point)});
        }

        vector<vector<int>> ans;
        while (k)
        {
            auto top = minHeap.top();
            minHeap.pop();

            ans.push_back(top.first);
            k--;
        }

        return ans;
    }
};

/*
Run the stimulation by always choosing the heaviest 2 stone, then smash it
Goal: Return the weight of the last remaining stone or return 0 if none remain

Intuition:
Since we need to always able to choose the 2 heaviest stone from the reaminig stone, this make
me think of using a heap because ican easily acces the 2 heaviest stone
*/
class Solution {
public:
    int lastStoneWeight(vector<int>& stones)
    {
        std::priority_queue<int, std::vector<int>, std::less<int>> maxHeap(stones.begin(), stones.end());

        while (maxHeap.size() > 1)
        {
            int stone1{maxHeap.top()};
            maxHeap.pop();
            int stone2{maxHeap.top()};
            maxHeap.pop();

            if (stone1 != stone2)
                maxHeap.emplace(std::abs(stone1 - stone2));
        }     

        return maxHeap.size() == 1? maxHeap.top() : 0;
    }
};

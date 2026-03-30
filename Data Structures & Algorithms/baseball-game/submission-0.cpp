/*
Operations:
'+': New Score sum of the previous 2 scores
'D': New score that is double of the previous score.
'C': Invalidate the previous score, removing it from the record

Goal: Return the sum of all the scores on the record after applying all the operations

Intuition:
Since the operation needed not just only the previous score but also needed the preivous 2 score.
So in order to keep track of the score, we need some sort of like stack to store the previous score which can be easily access.
And we also needed all the scores in the record, so stack will be the best data structure

*/
class Solution {
public:
    int calPoints(vector<string>& operations) 
    {
        std::deque<int> stack;

        for (const auto& operation : operations)
        {
            if (operation != "+" && operation != "D" && operation != "C")
                stack.emplace_back(std::stoi(operation));
            else if (operation == "+")
            {
                auto it{stack.rbegin()};
                int score = *it + *(++it);
                stack.emplace_back(score);
            }
            else if (operation == "D")
            {
                int prevScore = stack.back();
                stack.emplace_back(prevScore * 2);
            }
            else if (operation == "C")
                stack.pop_back();    
        }        

        int ttl{};

        while (!stack.empty())
        {

            ttl += stack.back();
            stack.pop_back();
        }
        return ttl;
    }
};
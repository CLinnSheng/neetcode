/*
asteriods[i] --> relative position in space & size
+ve --> Right Direction
-ve --> Left Direction
If 2 asteroids meet, the smaller one will explode.
If both same size, both explode. 2 asteroids moving in the same direction will never meet
Goal: Find out the state of the asteriods after all collisions.

Intuition:
Some key important observation we always need to keep track of the previous element that we
iterated through and also in the correct order
This lead to thinking of using a stack.

*/
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        std::deque<int> stack;

        for (const auto& asteroid : asteroids)
        {
            // Opposite direction then ok
            if (stack.empty() || (stack.back() < 0 && asteroid > 0) || (stack.back() < 0 && asteroid < 0) || (stack.back() > 0 && asteroid > 0))
                stack.emplace_back(asteroid);
            else if (stack.back() > 0 && asteroid < 0)
            {
                std::cout << asteroid << '\n';
                // Handle when they are going towards the same place
                // Left --> <-- Right
                int size = asteroid * -1;
                if (size == stack.back())
                    stack.pop_back();
                else if (stack.back() < size)
                {
                    while (!stack.empty() && stack.back() < size && stack.back() > 0 && asteroid < 0)
                        stack.pop_back();

                    if (!stack.empty() && stack.back() == size)
                        stack.pop_back();
                    else if (stack.empty() || (stack.back() > 0 && asteroid > 0) || (stack.back() < 0 && asteroid < 0))
                        stack.push_back(asteroid);
                }
            
            }
        }
        return std::vector<int>(stack.begin(), stack.end());
    }
};
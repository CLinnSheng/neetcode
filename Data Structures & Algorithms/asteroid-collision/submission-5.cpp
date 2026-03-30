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

        for (auto asteroid : asteroids)
        {
            // Only collides when prev one go the right && new one comes from the left
            while (!stack.empty() && stack.back() > 0 && asteroid < 0)
            {
                // Can use the diff
                // diff == 0, both explode
                // > 0, incoming explode
                // < 0, old 1 explode then need continue checking
                int diff{stack.back() + asteroid};
                if (diff == 0)
                {
                    stack.pop_back();
                    asteroid = 0;
                }
                else if (diff < 0)
                {
                    stack.pop_back();
                }
                else
                    asteroid = 0;

                if (!asteroid)
                    break;
            }
            if (asteroid)
                stack.push_back(asteroid);
        }
        return std::vector<int>(stack.begin(), stack.end());
    }
};
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        // Involve with previous element --> Stack
        // Each asteroid has its own direction
        // 2 with the same direction never meet
        // so keep popping until 2 consecutive rocks has the same direction
        std::deque<int> st;

        for (auto asteroid : asteroids)
        {
            if (st.empty())
            {
                st.push_back(asteroid);
            }
            else
            {
                bool exist = true;

                while (!st.empty() && st.back() > 0 && asteroid < 0)
                {
                    int diff = st.back() + asteroid;
                    if (diff == 0)
                    {
                        st.pop_back();
                        exist = false;
                    }
                    else if (diff < 0)
                    {
                        st.pop_back();
                    }
                    else
                    {
                        exist = false;
                    }

                    if (!exist)
                    {
                        break;
                    }
                }

                // If it still exist then push into it
                if (exist)
                {
                    st.push_back(asteroid);
                }
            }
        }
        return std::vector<int>(st.begin(), st.end());
    }
};
/*
Ok when ever that is a number of bracket we have to take care of the count of it and so to tackle
this when ever we face a close bracket then we need go back until we found the open bracket
thus in this situation we need to use stack more easier to track
*/
class Solution {
public:
    string decodeString(string s) 
    {
        std::string answer{};
        std::deque<std::string> st;
        int len = s.length(), index{};

        while (index < len)
        {            
            // Base Case
            if (st.empty() && isalpha(s[index]))
            {
                st.push_back(std::string(1, s[index]));
            }
            else
            {
                if (s[index] != ']')
                {
                    st.push_back(std::string(1, s[index]));
                }
                else
                {
                    std::string temp{};
                    // Reach Close bracket, then keep popping until we found a opening bracket
                    while (!st.empty() && st.back() != "[")
                    {
                        temp += st.back();
                        st.pop_back();
                    }
                    std::reverse(temp.begin(), temp.end());
                    st.pop_back(); // Popping the open bracket

                    std::string len_str{};

                    // Extract the number
                    while (!st.empty() && isdigit(st.back()[0]))
                    {
                        len_str += st.back();
                        st.pop_back();
                    }
                    std::reverse(len_str.begin(), len_str.end());
                    int temp_len = std::stoi(len_str);

                        // Push back into the stack again
                    for (int i{}; i < temp_len; i++)
                    {
                        for (char c : temp)               // ← push char by char
                        {
                            st.push_back(std::string(1, c));
                        }
                    }
                }
            }

            index++;
        }

        while (!st.empty())
        {
            answer += st.front();
            st.pop_front();
        }

        return answer;
    }
};
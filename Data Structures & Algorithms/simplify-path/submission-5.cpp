/*
Need to handle multpile "." properly nad "/"
The thing that we only need to store is just the directory
So we need a data structure easily adding and popping out of it, and
stack will be nice becaue of LIFO
And the directory's name are alwauys in between '/'
*/
class Solution {
public:
    string simplifyPath(string path) {
        std::deque<std::string> st;
        int len = path.length();
        int index{};

        while (index < len)
        {
            // Handle '/'
            while (index < len && path[index] == '/')
            {
                index++;
            }

            std::string token{};
            // Extract the token
            while (index < len && path[index] != '/')
            {
                token += path[index];
                index++;
            }

            if (token.empty())
            {
                break;
            }
            
            // Handle the token
            if (token == ".")
            {
                continue;
            }
            else if (token == "..")
            {
                if (!st.empty())
                {
                    st.pop_back();
                }
            }
            else
            {
                st.push_back(token);
            }
        }

        std::string answer{};

        // Base Case
        if (st.empty())
        {
            return "/";
        }

        while (!st.empty())
        {
            answer += "/" + st.front();
            st.pop_front();
        }
        return answer;
    }
};
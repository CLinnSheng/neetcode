class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        // Evaluate Expression --> Order does matter
        // Hence use stack
        std::deque<string> s;

        for (const auto &token : tokens)
        {
            if (s.empty())
            {
                s.push_back(token);
            }
            else if (token != "+" && token != "-" && token != "*" && token != "/")
            {
                s.push_back(token);
            }
            else
            {
                int val1 = std::stoi(s.back());
                s.pop_back();

                int val2 = std::stoi(s.back());
                s.pop_back();

                char operation = token[0];

                switch (operation)
                {
                    case '+':
                        s.push_back(std::to_string(val1 + val2));
                        break;

                    case '-':
                        s.push_back(std::to_string(val2 - val1));
                        break;

                    case '*':
                        s.push_back(std::to_string(val1 * val2));
                        break;

                    case '/':
                        s.push_back(std::to_string(val2 / val1));
                        break;
                }
            }    
        }    
        return std::stoi(s.back());
    }
};

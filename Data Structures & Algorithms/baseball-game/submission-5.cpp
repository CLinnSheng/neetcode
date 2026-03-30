class Solution {
public:
    int calPoints(vector<string>& operations) 
    {
        // Since need information from previous elemnet
        // use stack
        std::deque<std::string> st;

        for (const auto& operation : operations)
        {
            if (operation != "+" && operation != "D" && operation != "C")           
            {
                st.push_back(operation);
            }
            else if (operation == "+")
            {
                int elem_1 = std::stoi(st.back());
                st.pop_back();
                int elem_2 = std::stoi(st.back());
                st.pop_back();

                int new_elem = elem_1 + elem_2;

                st.push_back(std::to_string(elem_2));
                st.push_back(std::to_string(elem_1));
                st.push_back(std::to_string(new_elem));
            }
            else if (operation == "D")
            {
                int elem = std::stoi(st.back());
                st.push_back(std::to_string(elem * 2));
            }
            else
            {
                st.pop_back();
            }
        }    

        int sum{};
        while (!st.empty())
        {
            sum += std::stoi(st.back());
            st.pop_back();
        }

        return sum;
    }
};
class Solution {
public:
    void reverseString(vector<char>& s) {
        int size = s.size();
        int middle = size / 2;
        int ptr{};

        while (ptr < middle)
        {
            std::swap(s[ptr], s[size - ptr - 1]);
            ptr++;
        }
    }
};
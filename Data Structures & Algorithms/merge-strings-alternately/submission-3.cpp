class Solution {
public:
    string mergeAlternately(string word1, string word2) 
    {
        int len1 = word1.length(), len2 = word2.length();
        int ptr1{}, ptr2{};
        bool turn1 = true;
        std::string ans;

        while (ptr1 < len1 && ptr2 < len2)
        {
            if (turn1)
            {
                ans += word1[ptr1];
                ptr1++;
            }
            else
            {
                ans += word2[ptr2];
                ptr2++;
            }

            turn1 = !turn1;
        }

        // Append the remaining
        while (ptr1 < len1)
        {
            ans += word1[ptr1++];
        }
        while (ptr2 < len2)
        {
            ans += word2[ptr2++];
        }
        return ans;   
    }
};
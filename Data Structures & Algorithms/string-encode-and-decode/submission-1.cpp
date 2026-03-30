class Solution {
public:
// Intuition: Need to find a way to encode in order easy to decode
// first indicate the number of words and second the indicatoin when to start decode
    string encode(vector<string>& strs) {
        
        string encode_str = "";

        for (auto &str : strs)
            encode_str += to_string(str.size()) + "#" + str;
        
        return encode_str;
    }

    vector<string> decode(string s) {
        
        vector<string> ans;
        int index = 0;

        while (index < s.size()){
            // now need to find the # before deciding whats the length of the string
            // because the length might more than 9, can have 2 or more digits
            int pos = index;

            while (s[pos] != '#')
                pos++;
            
            int length = stoi(s.substr(index, pos - index));
            string sub_str = s.substr(pos + 1, length);

            index = pos + length + 1;
            ans.push_back(sub_str);
        }

        return ans;

    }
};

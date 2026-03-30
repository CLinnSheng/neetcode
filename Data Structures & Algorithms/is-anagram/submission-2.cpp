class Solution {
public:
    bool isAnagram(string s, string t) {
    
        ios_base :: sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int size_s = s.size(), size_t = t.size();

        if (size_s != size_t)   return false;

        unordered_map<char, int> map1;
        unordered_map<char, int> map2;

        for (int i = 0; i < size_s; i++){
            map1[s[i]]++;
            map2[t[i]]++;
        }

        for (auto &i : map1)
            if (i.second != map2[i.first])  return false;

        return true;
    }
};

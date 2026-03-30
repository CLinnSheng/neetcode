/*
Intuition:
The most appropriate data structure will using a hash map
and then for get we can just search through the string in O(n)
but we actually can furhter optimize it if u notice that
the timestamp will be sorted in ascending order
So we can makae use of binary search
*/
class TimeMap {
public:
    std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> map;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        if (!map.count(key))
            map[key] = std::vector<std::pair<std::string, int>>();

            map[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if (!map.count(key))
            return "";

        std::string str{};
        
        // O(n)
        // for (const auto& [val, time] : map[key])
        //     if (time <= timestamp)
        //         str = val;
        //     else
        //         break;

        // return str;

        // O(lgn)
        int size(map[key].size());
        int left{}, right(size - 1);
        while (left <= right)
        {
            int middle(left + (right - left) / 2);

            if (map[key][middle].second == timestamp)
                return map[key][middle].first;
            else if (map[key][middle].second <= timestamp)
            {
                str = map[key][middle].first;
                left = middle + 1;
            }       
            else
                right = middle - 1;
        }
        return str;
    }
};

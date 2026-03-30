/*
Any sequence of periods that does not match the rules ['.', '..'] should be treated as a valid
directory or file name. eg: '...', '......'

/// -> Treated as a single slash '/'

Goal: transform absolute path into its simplified canonical path

Intuition:
We need to have the information from previous directory. So we can use a stack to store
all the dir/file. Then pop it when ever we face '..'
Add it into the stack whenever the first time reach '/' means is the end of the file/dir name

*/
class Solution {
public:
    string simplifyPath(string path) 
    {
        std::deque<std::string> dirFile;
        // Skip the first because is always start from the root
        std::string currStr{};

        for (const char& c : path + '/')
        {
            if (c == '/')
            {
                // Check whether is it the first time?
                if (currStr == "..")
                {
                    if (!dirFile.empty())
                        dirFile.pop_back();
                }
                else if (!currStr.empty() && currStr != ".") // Handle Edge Case
                {
                    dirFile.push_back(currStr);
                }
                currStr.clear(); // '.' remain in the same dir
            }
            else
            {
                currStr += c;
            }
        }


        std::string ans{};
        while (!dirFile.empty())
        {
            ans += "/" + dirFile.front();
            dirFile.pop_front();
        }
        return ans.empty()? "/" : ans;    
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*
Goal: Serialize and deserialize the binary tree
Intuition: Serialize the binary tree through the way we traverse the tree
At here, we traverse the tree through preorder traversal because we want to build the tree from the top as the first node in preorder is the root node
we use a delimiter to seperate between each node in the string

For deserialize we just follow the way we traverse through the tree

Time Complexity: O(n)
Space Complexity: O(lgn)
*/
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        std::vector<string> encode_str;
        dfs_serialize(root, encode_str);

        // seperate each node with a delim
        return join(encode_str, '#');
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        std::vector<string> ParseString = split(data, '#');
        int index = 0;
        return dfs_deserialize(ParseString, index);
    }

    // Store it preorderly because is easier to track which nodes is leaf node
    // the last node that company by two nullptr will be the leaf node
    void dfs_serialize(TreeNode* root, std::vector<string>& str) {
        if (!root) {
            str.emplace_back("N");
            return ;
        }

        str.emplace_back(to_string(root->val));
        dfs_serialize(root->left, str);
        dfs_serialize(root->right, str);
    }

    TreeNode* dfs_deserialize(const std::vector<string>& ParseString, int& index) {
        if (ParseString[index] == "N") {
            index++;
            return nullptr;
        }

        // Preorder way to deserialize it because this is the way we serialize it
        TreeNode* node = new TreeNode(stoi(ParseString[index++]));
        node->left = dfs_deserialize(ParseString, index);
        node->right = dfs_deserialize(ParseString, index);
        
        return node;
    }
    
    std::vector<string> split(const std::string& targetStr, const char delim) {
        std::vector<string> parseString;
        std::stringstream s(targetStr);
        std::string temp;

        while (getline(s, temp, delim))
            parseString.emplace_back(temp);

        return parseString;
    }

    string join(std::vector<string>& str, const char delim) {
        std::stringstream s;
        for (const auto& i : str) {
            if (i != str[0]) s << delim;
            s << i;
        }
        return s.str();
    }
};

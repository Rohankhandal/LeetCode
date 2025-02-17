/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    void serial(TreeNode* root, string& ans) {
        if (root == NULL) {
            ans += "X,";
            return;
        }

        ans += to_string(root->val) + ",";
        serial(root->left, ans);
        serial(root->right, ans);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        serial(root, ans);
        return ans;
    }

    // Helper function for deserialization
    void deserial(vector<string>& arr, TreeNode*& ans, int& idx) {
        if (idx >= arr.size() || arr[idx] == "X") {
            idx++;
            return;
        }

        ans = new TreeNode(stoi(arr[idx]));
        idx++;
        deserial(arr, ans->left, idx);
        deserial(arr, ans->right, idx);
    }

    // Decodes the encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> v;
        string temp;
        stringstream str(data);

        while (getline(str, temp, ',')) {
            v.push_back(temp);
        }

        TreeNode* root = NULL;
        int idx = 0;
        deserial(v, root, idx);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
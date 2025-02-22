class Solution {
public:
    TreeNode* recoverFromPreorder(string s) {
        if (s.empty()) return NULL;
        
        unordered_map<int, TreeNode*> mp; // Level → Node Mapping
        int i = 0, n = s.size();
        
        while (i < n) {
            int level = 0;
            // Count the number of dashes to determine the level
            while (i < n && s[i] == '-') {
                level++;
                i++;
            }
            
            // Read the node value (handling multi-digit values)
            int val = 0;
            while (i < n && isdigit(s[i])) {
                val = val * 10 + (s[i] - '0');
                i++;
            }
            
            // Create a new node
            TreeNode* node = new TreeNode(val);
            
            // If it's not the root, attach it to its parent
            if (level > 0) {
                TreeNode* parent = mp[level - 1]; // Get parent from map
                if (!parent->left) {
                    parent->left = node;
                } else {
                    parent->right = node;
                }
            }
            
            // Store current node at this level
            mp[level] = node;
        }
        
        return mp[0]; // Root node
    }
};

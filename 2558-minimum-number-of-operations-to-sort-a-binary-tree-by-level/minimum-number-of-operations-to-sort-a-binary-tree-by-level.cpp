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
class Solution {
public:
    void solve(TreeNode* root, int &ans) {
        if (root == NULL) return;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int sz = q.size();
            vector<int> temp;
            
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            vector<int> sortedArray = temp;
            sort(sortedArray.begin(), sortedArray.end());
            unordered_map<int, int> mp;
            
            for (int i = 0; i < sz; i++) {
                mp[temp[i]] = i;
            }
            
            for (int i = 0; i < sz; i++) {
                if (sortedArray[i] != temp[i]) {
                    int originalIndex = mp[sortedArray[i]];
                    swap(temp[i], temp[originalIndex]);
                    
                    // Update the map after swapping
                    mp[temp[originalIndex]] = originalIndex;
                    mp[temp[i]] = i;
                    
                    ans++;
                }
            }
        }
    }
    
    int minimumOperations(TreeNode* root) {
        int swapCount = 0;
        solve(root, swapCount);
        return swapCount;
    }
};

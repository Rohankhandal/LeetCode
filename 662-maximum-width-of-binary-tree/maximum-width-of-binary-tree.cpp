/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        ll maxWidth = 0;
        while (!q.empty()) {
            ll l = q.front().second;
            ll r = q.back().second;
            // cout<<l<<" "<<r<<endl;
            maxWidth = max(maxWidth, r - l + 1);
            // cout<<maxWidth<<endl;
            int size = q.size();
            
            while (size--) {
                TreeNode* node = q.front().first;
                ll index = q.front().second;
                q.pop();

                if (node->left) {
                    q.push({node->left, (2 * index + 1)});
                }
                if (node->right) {
                    q.push({node->right, (2 * index + 2)});
                }
            }
        }
        return maxWidth;
    }
};
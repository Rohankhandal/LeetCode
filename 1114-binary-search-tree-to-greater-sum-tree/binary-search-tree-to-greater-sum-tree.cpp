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
    void solve(TreeNode* root, int &accumulatedSum) {
        if (root == nullptr) return;
        
        // Traverse the right subtree first
        solve(root->right, accumulatedSum);
        
        // Update the current node's value with the accumulated sum
        accumulatedSum += root->val;
        root->val = accumulatedSum;
        
        // Traverse the left subtree
        solve(root->left, accumulatedSum);
    }

    TreeNode* bstToGst(TreeNode* root) {
        int accumulatedSum = 0;
        solve(root, accumulatedSum);
        return root;
    }
};

#include <unordered_map>

class Solution {
public:
    // Memoization map: stores {TreeNode*, pair<robbed, notRobbed>}
    unordered_map<TreeNode*, pair<int, int>> memo;

    int rob(TreeNode* root) {
        pair<int, int> result = solve(root);
        return max(result.first, result.second); // max(robbed, notRobbed)
    }
    
    // solve function returns a pair {robbed, notRobbed}
    pair<int, int> solve(TreeNode* root) {
        if (root == nullptr) {
            return {0, 0};  // {robbed = 0, notRobbed = 0}
        }
        
        // Check memoization
        // if (memo.find(root) != memo.end()) {
        //     return memo[root];
        // }
        
        // Recursively solve for left and right subtrees
        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);
        
        // If we rob this node, we cannot rob its children
        int robbed = root->val + left.second + right.second;
        
        // If we don't rob this node, we can choose to rob or not rob its children
        int notRobbed = max(left.first, left.second) + max(right.first, right.second);
        
        // Store the result in memo map
        // memo[root] = {robbed, notRobbed};
        
        // return memo[root];
        return {robbed, notRobbed};

    }
};

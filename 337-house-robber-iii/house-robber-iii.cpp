class Solution {
public:
    // Memoization map: stores {TreeNode* -> [robbed, notRobbed]}
    unordered_map<TreeNode*, vector<int>> memo;
    
    int rob(TreeNode* root) {
        return max(solve(root, true), solve(root, false));
    }
    
    int solve(TreeNode* root, bool thief) {
        if (root == nullptr) {
            return 0;
        }
        
        // Check memoization map
        if (memo.find(root) != memo.end()) {
            if (memo[root][thief] != -1) {
                return memo[root][thief];
            }
        } else {
            // Initialize memo for this node with two -1 values
            memo[root] = vector<int>(2, -1);  // -1 indicates not yet computed
        }
        
        int take = 0, skip = 0;
        
        if (thief) {
            take = root->val + solve(root->left, false) + solve(root->right, false);
        }
        
        skip = solve(root->left, true) + solve(root->right, true);
        
        // Store the result in memo map
        memo[root][thief] = max(take, skip);
        
        return memo[root][thief];
    }
};

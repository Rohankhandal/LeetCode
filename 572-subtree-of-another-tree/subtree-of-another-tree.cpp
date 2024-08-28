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

// e.g:-root = [1,1] subRoot = [1]  and OUTPUT :- true
class Solution {
public:
    // Function to check if the current subtree of 'root' matches 'subRoot'
    bool isSubRoot(TreeNode* root, TreeNode* subRoot) {
        // If both the root and subRoot are null, they are identical
        if (root == NULL && subRoot == NULL) return true;

        // If root is null but subRoot is not, or vice versa, they are not identical
        if (subRoot != NULL && root == NULL) return false;
        if (subRoot == NULL && root != NULL) return false;

        // If the values of the current nodes do not match, return false
        if (root->val != subRoot->val) return false;

        // Recursively check the left and right subtrees
        bool left = isSubRoot(root->left, subRoot->left);
        bool right = isSubRoot(root->right, subRoot->right);

        // Both left and right subtrees must match
        return left && right;
    }

    // Function to determine if 'subRoot' is a subtree of 'root'
    bool solve(TreeNode* root, TreeNode* subRoot) {
        // If the root is null, no further checks needed
        if (root == NULL) return false;

        // If the current node's value matches subRoot's value, check if the trees match
        if (root->val == subRoot->val) {
            if (isSubRoot(root, subRoot))   //if not match , then continue matching
                return true; // If they match, return true
        }

        // Recursively check the left and right subtrees of the current node
        bool left = solve(root->left, subRoot);
        bool right = solve(root->right, subRoot);

        // Return true if either the left or right subtree matches
        return left || right;
    }

    // Main function to check if 'subRoot' is a subtree of 'root'
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // If the root is null, subRoot cannot be a subtree, return false
        if (root == NULL) return true;

        // Start the subtree check
        return solve(root, subRoot);
    }
};

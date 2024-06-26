
// Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    // Helper function to perform in-order traversal of the BST
    // and store the values in a vector.
    void traverse(TreeNode* root, vector<int>& arr) {
        if (root == nullptr) return;  // Base case: if the node is null, return
        traverse(root->left, arr);    // Recursively traverse the left subtree
        arr.push_back(root->val);     // Visit the root node
        traverse(root->right, arr);   // Recursively traverse the right subtree
    }

    // Helper function to construct a balanced BST from the sorted values.
    TreeNode* solve(vector<int>& arr, int l, int r) {
        if (l > r) return nullptr;    // Base case: if the left index exceeds the right, return null

        int mid = (l + r) / 2;        // Find the middle index
        TreeNode* root = new TreeNode(arr[mid]);  // Create a new node with the middle element

        // Recursively construct the left and right subtrees
        root->left = solve(arr, l, mid - 1);
        root->right = solve(arr, mid + 1, r);

        return root;  // Return the root of the subtree
    }

    // Main function to balance the BST.
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inOrder;  // Vector to store the in-order traversal
        traverse(root, inOrder);  // Get the in-order traversal of the BST

        // Use the sorted in-order traversal to construct a balanced BST
        return solve(inOrder, 0, inOrder.size() - 1);
    }
};

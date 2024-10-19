class Solution {
public:
    bool check(TreeNode* root, int &size, int &height) {
        if (!root->left && !root->right) {  // Leaf node is perfect, height = 0
            height = 0;
            return true;
        }
        if (root->left == NULL || root->right == NULL) return false;  // One child is missing
        
        int leftSize = 1, rightSize = 1;
        int leftHeight = 0, rightHeight = 0;
        
        // Check if left and right subtrees are perfect and calculate their sizes and heights
        bool left = check(root->left, leftSize, leftHeight);
        bool right = check(root->right, rightSize, rightHeight);

        // Both subtrees must be perfect and of equal height for the whole subtree to be perfect
        if (left && right && leftHeight == rightHeight) {
            size = leftSize + rightSize + 1;  // Total size includes left, right and root
            height = leftHeight + 1;  // The height of the current subtree is 1 + height of its children
            return true;
        } else {
            size = 0;  // If not perfect, reset size
            return false;
        }
    }

    void solve(TreeNode* root, vector<int>& arr) {
        if (root == NULL) return;

        solve(root->left, arr);
        solve(root->right, arr);

        int size = 1, height = 0;
        if (check(root, size, height)) arr.push_back(size);  // If perfect subtree, add its size to arr
    }

    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        vector<int> arr;
        solve(root, arr);
        sort(arr.rbegin(), arr.rend());  // Sort in descending order

        if (k > arr.size()) return -1;  // Edge case: Not enough perfect subtrees
        return arr[k-1];  // Return the k-th largest (1-based index)
    }
};

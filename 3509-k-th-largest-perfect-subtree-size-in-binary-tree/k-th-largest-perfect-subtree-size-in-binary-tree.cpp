//The make_tree function traverses the entire tree once, taking O(n) time.
// During this traversal, it populates the ans vector with the sizes of perfect subtrees.
// After the traversal, sorting the ans vector takes O(p log p) time, where p is the number of perfect subtrees found (which is at most n).

// Therefore, the overall time complexity is O(n + p log p), where n is the number of nodes in the tree and p is the number of perfect subtrees.
class Solution {
public:
    vector<int> ans;  // Stores sizes of perfect subtrees

    // Recursive function to check for perfect subtrees and collect their sizes
    pair<bool,int> make_tree(TreeNode* root) {
        if (root == NULL) {
            return {true, 0};  // Empty tree is considered perfect
        }

        // Recursively check left and right subtrees
        pair<bool,int> l = make_tree(root->left);
        pair<bool,int> r = make_tree(root->right);

        // If both subtrees are perfect and have the same size
        if (l.first && r.first && l.second == r.second) {
            int s = l.second + r.second + 1;  // Size of current subtree
            ans.push_back(s);  // Add size to our list
            return {true, s};  // Current subtree is perfect
        }

        return {false, 0};  // Not a perfect subtree
    }

    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        if (root == NULL) {
            return -1;
        }

        ans.clear();  // Reset our list of sizes
        make_tree(root);  // Populate ans with sizes of perfect subtrees

        // Sort sizes in descending order
        sort(ans.begin(), ans.end(), greater<int>());

        // Return kth largest if it exists, else -1
        if (ans.size() >= k) {
            return ans[k-1];
        }
        return -1;
    }
};
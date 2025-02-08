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
//T.C:-O(Nlog(N)) S.c:-O(N)
class Solution {
public:
    // Map to store inorder index positions for quick lookup
    unordered_map<int, int> inorderMap;
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int& preIndex, int inStart, int inEnd) {
        if (inStart > inEnd) return NULL;

        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int inIndex = inorderMap[rootVal]; // Get index in inorder traversal

        // Recursively build left and right subtrees
        root->left = buildTree(preorder, inorder, preIndex, inStart, inIndex - 1);
        root->right = buildTree(preorder, inorder, preIndex, inIndex + 1, inEnd);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;  // Copy preorder to get inorder
        sort(inorder.begin(), inorder.end()); // Sorting gives inorder traversal
        
        // Store inorder indices for quick lookup
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }

        int preIndex = 0;
        return buildTree(preorder, inorder, preIndex, 0, inorder.size() - 1);
    }
};
//Brute FOrce T.C:-O(N^2) S.C:-O(N)
// class Solution {
// public:
//     // Function to insert a node in the BST
//     TreeNode* insert(TreeNode* root, int val) {
//         if (!root) return new TreeNode(val); // Create new node if empty
        
//         if (val < root->val) root->left = insert(root->left, val); // Go left
//         else root->right = insert(root->right, val); // Go right
        
//         return root;
//     }

//     TreeNode* bstFromPreorder(vector<int>& preorder) {
//         if (preorder.empty()) return NULL;
        
//         TreeNode* root = new TreeNode(preorder[0]); // First element is the root
        
//         // Insert each element into BST
//         for (int i = 1; i < preorder.size(); i++) {
//             insert(root, preorder[i]);
//         }

//         return root;
//     }
// };




//  Method:3 T,C- O(3N) S.C:-(1)
// class Solution {
// public:
//     // Helper function to build BST using preorder traversal
//     TreeNode* buildBST(vector<int>& preorder, int& index, int minVal, int maxVal) {
//         if (index >= preorder.size()) return NULL;

//         int val = preorder[index];
//         if (val < minVal || val > maxVal) return NULL; // Value is out of bounds

//         // Create the current node
//         TreeNode* root = new TreeNode(val);
//         index++; // Move to the next element

//         // Construct the left and right subtrees with updated bounds
//         root->left = buildBST(preorder, index, minVal, val);
//         root->right = buildBST(preorder, index, val, maxVal);

//         return root;
//     }

//     TreeNode* bstFromPreorder(vector<int>& preorder) {
//         int index = 0;
//         return buildBST(preorder, index, INT_MIN, INT_MAX);
//     }
// };
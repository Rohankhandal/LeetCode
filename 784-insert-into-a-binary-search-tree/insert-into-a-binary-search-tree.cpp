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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // If the root node is NULL, create a new node
        // with the given value and return it as the new root.
        if(root==NULL){
            return new TreeNode(val);
        }
        
        // cur pointer to traverse the tree
        TreeNode* cur = root;
        
        // While loop to traverse the tree to find
        // the appropriate position for insertion.
        while(true){
            // If the current node's value is less
            // than or equal to the value to be inserted,
            // move to the right subtree.
            if(cur->val <= val){
                // If the right child of the current node
                // is not NULL, update 'cur' to the right child.
                if(cur->right !=NULL){
                    cur = cur->right;
                }
                // If the right child is NULL, create a new node
                // with the given value as the right child
                // and exit the while loop.
                else{
                    cur->right = new TreeNode(val);
                    break;
                }
            }
            // If the current node's value is greater than
            // the value to be inserted,
            // move to the left subtree.
            else{
                // If the left child of the current node
                // is not NULL, update 'cur' to the left child.
                if(cur->left !=NULL){
                    cur = cur->left;
                }
                // If the left child is NULL, create a new node
                // with the given value as the left child
                // and exit the while loop.
                else{
                    cur->left = new TreeNode(val);
                    break;
                }
            }
        }
        // Return the root of the
        // modified tree after insertion.
        return root;
    }
};
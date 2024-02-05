/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)  //empty tree
        {
            return NULL;
        }
        if(root->val<p->val && root->val<q->val)
        {
            //case 1:right subtree
            return lowestCommonAncestor(root->right,p, q);
        }
        else  if(root->val>p->val && root->val>q->val)
        {
            // case 2: left subtree 
            return lowestCommonAncestor(root->left,p, q);
        }
        else {
            // case 3 and case 4
            //root is answer    
            return root;
        }
        // //case 3
        // else if(p->val < root->val && q->val > root->val) {
        //     return root;
        // }
        // //case 4
        // else if(q->val < root->val && p->val > root->val) {
        //     return root;
        // }
    }
};
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
    bool isSubRoot(TreeNode*root,TreeNode* subRoot)
    {
        if(root==NULL && subRoot==NULL) return true;
        // if(subRoot==NULL) return true;

        if(subRoot!=NULL && root==NULL) return false;
        if(subRoot==NULL && root!=NULL) return false;
        if(root->val!=subRoot->val) return false;

        bool left=isSubRoot(root->left,subRoot->left);

        bool right=isSubRoot(root->right,subRoot->right);

        return left&&right;
    }
    bool solve(TreeNode* root,TreeNode*subRoot)
    {
        if(root==NULL) return false;

        if(root->val==subRoot->val)
        {
            if(isSubRoot(root,subRoot))
                return true;
        }

        bool left=solve(root->left,subRoot);
        bool right=solve(root->right,subRoot);

        return left||right;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL) return true;

        return solve(root,subRoot);
    }
};
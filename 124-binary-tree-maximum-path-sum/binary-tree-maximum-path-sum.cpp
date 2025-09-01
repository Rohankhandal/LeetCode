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
    int f(TreeNode*root,int &ans){
        if(!root) return 0;

        int l=f(root->left,ans);
        int r=f(root->right,ans);
        
        ans=max({ans,l+r+root->val,root->val+max(l,r),root->val});
        return max(root->val+max(l,r),root->val);
    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        f(root,ans);
        return ans;   
    }
};
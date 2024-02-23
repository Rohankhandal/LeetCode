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
int height(TreeNode*root)
{
    if(root==NULL) return 0;
    int lh=height(root->left);
    int rh=height(root->right);
    return max(lh,rh)+1;
}
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
          return true;
        
        int left=height(root->left);
        int right=height(root->right);
        int diff=abs(left-right);
        bool ans;
          if(diff<=1)
            ans=true;
         else 
            return false;
        bool leftAns=isBalanced(root->left);
        bool rightAns=isBalanced(root->right);
        return ans&&leftAns&&rightAns;
    }
};
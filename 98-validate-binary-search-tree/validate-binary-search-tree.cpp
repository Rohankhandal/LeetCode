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
bool helper(TreeNode* root,long long lb,long long ub)  //upperbound,lowerbound
{
    if(root==NULL) return true;

    if(root->val > lb && root->val < ub)
    {
        bool leftAns=helper(root->left,lb,root->val);
        bool rightAns=helper(root->right,root->val,ub);
        return leftAns&&rightAns;
    }
    else{
        return false;
    }
}
    bool isValidBST(TreeNode* root) {
        long long MAXI=10e15;
        long long MINI=-10e15;
       
        return  helper(root,MINI,MAXI);
    }
};
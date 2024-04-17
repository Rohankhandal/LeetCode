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
  void solve(TreeNode*root,string &ans,string curr)
  {
    if(root==NULL) return ;
    if(root->left==NULL and root->right==NULL)
    {
        curr=((char)(root->val+'a'))+curr;   //add leaf node data
        if(ans=="" || ans>curr)
        {
            ans=curr;
            return ;
        }
    }
    curr=((char)(root->val+'a'))+curr;             //(IMP)adding the character in starting of string 
     solve(root->left,ans,curr);
    solve(root->right,ans,curr);
  }

    string smallestFromLeaf(TreeNode* root) {
        string ans="";
        string curr="";
        solve(root,ans,curr);
        return ans;
    }
};
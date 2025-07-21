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
    TreeNode* f(vector<int>&inorder,int l,int r)
    {
        if(l>r) return NULL;

        int mid=(l+r)/2;

        TreeNode* node=new TreeNode(inorder[mid]);
        node->left=f(inorder,l,mid-1);
        node->right=f(inorder,mid+1,r);

        return node;
    }
    void traverse(TreeNode* root,vector<int>&inorder)
    {
        if(root==NULL) return ;

        traverse(root->left,inorder);
        inorder.push_back(root->val);
        traverse(root->right,inorder);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>inorder;
        traverse(root,inorder);

        return f(inorder,0,inorder.size()-1);
    }
};
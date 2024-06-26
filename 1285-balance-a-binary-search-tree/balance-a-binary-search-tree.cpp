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
    void traverse(TreeNode*root,vector<int>&arr)
    {
        if(root==NULL) return ;
        traverse(root->left,arr);
        arr.push_back(root->val);
        traverse(root->right,arr);
    }
    TreeNode* solve(vector<int>&arr,int l,int r)
    {
        if(l>r) return NULL;
        
            int mid=(l+r)/2;
            TreeNode* root=new TreeNode(arr[mid]);
            root->left=solve(arr,l,mid-1);
            root->right=solve(arr,mid+1,r);

            return root;        
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>inOrder;
        traverse(root,inOrder);
        int l=0,r=inOrder.size()-1;
        return solve(inOrder,l,r);

    }
};
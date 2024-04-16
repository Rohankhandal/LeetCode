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
    void solve(TreeNode* &root,int val,int depth,int height)
    {
        if(root==NULL) return ;
        
        if(height==depth)
        {
            TreeNode* leftPart=root->left;
            TreeNode* rightPart=root->right;

            TreeNode*newLeft=new TreeNode(val);
            TreeNode*newRight=new TreeNode(val);

            root->left=newLeft;
            root->right=newRight;
            newLeft->left=leftPart;
            newRight->right=rightPart;
            return ;
        }
        else if(height>depth) return ;

        solve(root->left,val,depth,height+1);
        solve(root->right,val,depth,height+1);

    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)
        {
            TreeNode* newRoot=new TreeNode(val);
            newRoot->left=root;
            return newRoot;
        }
        int tempDepth=2;
        solve(root,val,depth,tempDepth);
        return root;
    }
};
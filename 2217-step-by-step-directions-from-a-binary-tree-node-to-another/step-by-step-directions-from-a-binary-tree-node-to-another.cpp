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
    TreeNode* lca(TreeNode* root, int startValue, int destValue)
    {
        if(root==NULL) return NULL;
        if(root->val==startValue) return root;
        if(root->val==destValue) return root;

        TreeNode *left=lca(root->left,startValue,destValue);
        TreeNode *right=lca(root->right,startValue,destValue);

        if(left==NULL && right==NULL) return NULL;
        else if(left!=NULL && right==NULL) return left;
        else if(left==NULL && right!=NULL) return right;
        else return root;

    }
    bool findPath(TreeNode* root,int target,string &path)
    {
        if (root == nullptr) return false;
        if (root->val == target) return true;

        path += 'L';
        if (findPath(root->left, target, path)) return true;
        path.pop_back();

        path += 'R';
        if (findPath(root->right, target, path)) return true;
        path.pop_back();

        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode *LCA=lca(root,startValue,destValue);
        string leftPath="";
        string rightPath="";

        findPath(LCA,startValue,leftPath);
        findPath(LCA,destValue,rightPath);

        for(char &ch:leftPath)
        {
            ch='U';
        }

        return leftPath+rightPath;
    }
};
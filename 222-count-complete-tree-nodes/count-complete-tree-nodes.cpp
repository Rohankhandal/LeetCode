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

//  T.c:-O((logn)^2);

class Solution {
public:
int getLeftHeight(TreeNode*root)
{
    if(root==NULL) return 0;
    TreeNode*temp=root;
    int count=0;
    while(temp)
    {
        count++;
        temp=temp->left;
    }
    return count;
}
int getRightHeight(TreeNode*root)
{
    if(root==NULL) return 0;
    TreeNode*temp=root;
    int count=0;
    while(temp)
    {
        count++;
        temp=temp->right;
    }
    return count;
}
    int countNodes(TreeNode* root) {
        if(root==NULL)
        return 0;

        int leftHeight=getLeftHeight(root);
        int rightHeight=getRightHeight(root);

        if(leftHeight==rightHeight) return pow(2,leftHeight)-1;
        //perfect complete binary tree

        return countNodes(root->left)+1+countNodes(root->right);
    }
};
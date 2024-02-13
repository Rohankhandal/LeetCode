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
int find(vector<int>&inorder,int size,int ele)
{
    for(int i=0;i<size;i++)
    {
        if(inorder[i]==ele){
            return i;
        }
    }
    return -1;
}
TreeNode* solve(vector<int>&inorder,vector<int>&postorder,int size,int inorderStart,int inorderEnd,int &postIndex)
{
    if(postIndex<0 || inorderStart>inorderEnd)
    {
        return NULL;
    }
    int ele=postorder[postIndex--];
    TreeNode* root=new TreeNode(ele);
    int index=find(inorder,size,ele);

    //right call
    root->right=solve(inorder,postorder,size,index+1,inorderEnd,postIndex);

    //left call
    root->left=solve(inorder,postorder,size,inorderStart,index-1,postIndex);

    return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size=inorder.size();
        int inorderStart=0;
        int inorderEnd=size-1;
        int postIndex=size-1;
        TreeNode* root=solve(inorder,postorder,size,inorderStart,inorderEnd,postIndex);
        return root;
    }
};
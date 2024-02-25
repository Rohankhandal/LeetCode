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
int search(int target,vector<int>inorder,int size)
{
    
    for(int i=0;i<size;i++)
    {
        if(inorder[i]==target) return i;
    }
    return 0;
}
TreeNode* helper(vector<int>&preorder,vector<int>&inorder,int size,int &preIndex,int
                inStart,int inEnd)
        {
            if(preIndex > size ||inStart > inEnd)
            {
                return NULL;
            }
            int findEle=preorder[preIndex++];
            int eleIndex=search(findEle,inorder,size);
            TreeNode* root=new TreeNode(findEle);
            root->left=helper(preorder,inorder,size,preIndex,inStart,eleIndex-1);
            root->right=helper(preorder,inorder,size,preIndex,eleIndex+1,inEnd);

            return root;

        }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex=0;
        int inStart=0;
        int inEnd=inorder.size()-1;
        int size=preorder.size();
     
        return helper(preorder,inorder,size,preIndex,inStart,inEnd);

    }
};
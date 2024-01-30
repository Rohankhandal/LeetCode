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
//Fast method:-
class Solution {
public:
int D=0;
    int height(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int lh=height(root->left);
        int  rh=height(root->right);
        //diameter
        int currD=lh+rh;
        D=max(currD,D);
        int ans=max(lh,rh)+1;
        return ans;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return D;
    }
};

 //It is slow method bcz Tc:-O(n^2) 

// class Solution {
// public:
//     int height(TreeNode* root)
//     {
//         if(root==NULL)
//         {
//             return 0;
//         }
//         int lh=height(root->left);
//         int  rh=height(root->right);
//         int ans=max(lh,rh)+1;
//         return ans;
//     }
    
//     int diameterOfBinaryTree(TreeNode* root) {
//         //base condition 
//         if(root == NULL)
//         {
//             return 0;
//         }
//         //left subtree check
//         int lh=diameterOfBinaryTree(root->left);
//          //right subtree check
//         int rh=diameterOfBinaryTree(root->right);
//         //root is included in answer
//         int op3=height(root->left)+height(root->right);
//         int ans=max(lh,max(rh,op3));

//         return ans;
//     }
// };
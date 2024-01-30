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

    bool isSameTree(TreeNode* p, TreeNode* q) {
       if(!p && !q)   //when both are  equal to NULL
       {
           return true;
       }
       if(p && q)  //when both are not equal to NULL
       {
           return (p->val == q->val) && isSameTree(p->left,q->left)
           && isSameTree(p->right,q->right);
       }
       return false;  //when p or q are NULL
    }
};
// class Solution {
// public:
// bool solve(TreeNode* p, TreeNode* q)
// {
//     if(p==NULL && q == NULL){
//         return true;
//     }
//     if(p==NULL)
//     {
//         return false;
//     }
//     if(q==NULL)
//     {
//         return false;
//     }
//     if(p->val!=q->val)
//     {
//         return false;
//     }
//     bool res1=solve(p->left,q->left);
//     bool res2=solve(p->right,q->right);
//     return res1 && res2;
// }
//     bool isSameTree(TreeNode* p, TreeNode* q) {
//         bool result=solve(p,q);
//         return result;
//     }
// };
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
    void solve(TreeNode*root,int&sum,int temp){
        if(root==NULL) return ;
        if(root->left==NULL && root->right==NULL)
        {
            cout<<temp<<endl;
            sum+=temp;
            return ;
        }
        
        int val=0;
        int ans=temp;
        if(root->left) 
        {
            val=root->left->val;
            ans=ans*10+val;
        }
        solve(root->left,sum,ans);

        val=0;
        ans=temp;
        if(root->right)
        {
            val=root->right->val;
            ans=ans*10+val;
        } 
        solve(root->right,sum,ans);

    }
    int sumNumbers(TreeNode* root) {
        int sum=0;
        solve(root,sum,root->val);
        return sum;
    }
};
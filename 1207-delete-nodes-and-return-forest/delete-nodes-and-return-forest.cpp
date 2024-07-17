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
    void solve(TreeNode* &root,  unordered_map<int,int>&mp,vector<TreeNode*>&ans)
    {
        if(root==NULL) return ;

        solve(root->left,mp,ans);
        solve(root->right,mp,ans);

        if(mp.find(root->val)!=mp.end())
        {
            if(root->left!=NULL) ans.push_back(root->left);
            if(root->right!=NULL) ans.push_back(root->right);
            root=NULL;
        }





    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*>ans;
        unordered_map<int,int>mp;
        for(auto &it:to_delete)
        {
            mp[it]++;
        }
        if(mp.find(root->val)==mp.end()) ans.push_back(root);
        solve(root,mp,ans);
        return ans;
        
    }
};
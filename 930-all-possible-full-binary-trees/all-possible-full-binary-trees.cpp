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
//Memoziation
    unordered_map<int,vector<TreeNode*>>mp;
    vector<TreeNode*>solve(int n)
    {
        if(n%2==0) //Even nodes can't make Full Binary Tree
        {
            return {};
        }
        if(n==1)
        {
            TreeNode* node = new TreeNode(0);
            return {node};
        }
        if(mp.find(n) != mp.end())
            return mp[n];
        vector<TreeNode*>ans;
        for(int i=1;i<n;i+=2)  //bcz for even values there is no possible FULL BINARY TREE
        {
            vector<TreeNode*>left=solve(i);
            vector<TreeNode*>right=solve(n-i-1);

            for(auto &l:left)
            {
                for(auto &r:right)
                {
                    TreeNode*root=new TreeNode(0);
                    root->left=l;
                    root->right=r;

                    ans.push_back(root);
                }
               
            }
        }
        return mp[n]=ans;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        return solve(n);

    }
};
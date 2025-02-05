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
    bool isMatch(TreeNode*p,TreeNode*q)
    {
        if(!p && !q) return true;
        if(!p || !q) return false;

        if(p->val!=q->val) return false;

        bool lh=isMatch(p->left,q->left);
        bool lr=isMatch(p->right,q->right);

        return lh&&lr;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q) return false;
        return (p->val==q->val && isMatch(p->left,q->left) && isMatch(p->right,q->right));
    }
};
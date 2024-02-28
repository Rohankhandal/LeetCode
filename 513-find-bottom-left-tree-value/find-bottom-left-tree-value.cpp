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
    int findBottomLeftValue(TreeNode* root) {
        if(root==NULL) return 0;
        queue<TreeNode*>q;
        q.push(root);
        int ans=0;
        while(!q.empty())
        {
            int size=q.size();
            ans=q.front()->val;  //insert the leftmost node value while traverse a level
            for(int i=0;i<size;i++)
            {
                TreeNode*temp=q.front();
                q.pop();
                if(temp->left)
                {
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                }
            }
            
        }
        return ans;
    }
};



//Approach-1 (Using DFS)
//T.C : O(n)
//S.C : O(max depth of tree)
// class Solution {
// public:
//     int maxDepth;
//     int bottomLeft;
    
//     void solve(TreeNode* root, int currDepth) {
//         if(!root) {
//             return;
//         }
        
//         if(currDepth > maxDepth) {
//             maxDepth   = currDepth;
//             bottomLeft = root->val;
//         }
        
//         solve(root->left, currDepth+1);
//         solve(root->right, currDepth+1);
//     }
    
//     int findBottomLeftValue(TreeNode* root) {
//         maxDepth = -1;
        
//         solve(root, 0);
//         return bottomLeft;
        
//     }
// };
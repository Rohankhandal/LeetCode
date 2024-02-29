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
    bool isEvenOddTree(TreeNode* root) {
        if(root==NULL) return true;
        queue<TreeNode*>q;
        q.push(root);
        bool LtoR=true;
        while(!q.empty())
        {
            int size=q.size();
            vector<int>ans(size);
            for(int i=0;i<size;i++)
            {
                int index=LtoR==true?i:size-i-1;   
                //in even level we insert value in vector from left to right , and in 
                //odd level we insert value in vector from right  to left,
                //so that we only want to check stricly increasing for both even and odd level
                TreeNode*temp=q.front();
                q.pop();
                ans[index]=temp->val;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            if(LtoR) //true means even level
            {
                
                if(ans[0]%2==0)
                {
                    return false;
                }
                for(int i=1;i<size;i++)
                {
                    if(ans[i]<=ans[i-1] || ans[i]%2==0)
                        return false;
                }
            }
            else
            {
                if(ans[0]%2==1)
                {
                    return false;
                }
                for(int i=1;i<size;i++)
                {
                    if(ans[i]<=ans[i-1] || ans[i]%2==1)
                        return false;
                }
            }

            LtoR=!LtoR;
            //check strictly increasing
        }
        return true;
    }
};
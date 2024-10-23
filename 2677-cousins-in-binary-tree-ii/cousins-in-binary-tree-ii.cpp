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
    vector<int> getLevelSum(TreeNode*root)
    {
        vector<int>levelSum;
        int level=0;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            int sz=q.size();
            int sum=0;
            for(int i=0;i<sz;i++)
            {
                TreeNode*temp=q.front(); q.pop();

                sum+=temp->val;
                if(temp->left) q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
            levelSum.push_back(sum);
        }
        return levelSum;
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int>levelSum=getLevelSum(root);
        for(auto &it:levelSum)
        {
            cout<<it<<" ";
        }
        vector<int>ans;
        queue<TreeNode*>q;
       
        root->val=0;
        q.push(root);
        int level=1;
        while(!q.empty() && level<levelSum.size())
        {
            int sz=q.size();
            int currLvlSum=levelSum[level];
            for(int i=0;i<sz;i++)
            {
                TreeNode*temp=q.front(); q.pop();
                int leftnewValue=-1;
                int rightnewValue=-1;

                if(temp->left)
                {
                    int sum=temp->left->val;
                    if(temp->right) sum+=temp->right->val;

                    int remSum=currLvlSum-sum;
                    // cout<<level<<" -LEFT- "<<remSum<<endl;
                    leftnewValue=remSum;
                }
                if(temp->right)
                {
                    int sum=temp->right->val;
                    // cout<<sum<<endl;
                    if(temp->left)
                    {
                     sum+=temp->left->val;
                    //  cout<<"YES"<<endl;
                    }
                    // cout<<sum<<endl;
                 
                    int remSum=currLvlSum-sum;
                    //  cout<<level<<" -RIGHT- "<<sum<<" "<<remSum<<endl;
                    temp->right->val=remSum;
                }
                if(leftnewValue!=-1) temp->left->val=leftnewValue;


                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }   
            level++;
        }
        return root;
    }
};
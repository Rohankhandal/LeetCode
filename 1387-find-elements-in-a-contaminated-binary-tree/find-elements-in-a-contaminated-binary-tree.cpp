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
class FindElements {
public:
    unordered_map<int,int>freq;
    void bfs(TreeNode*root)
    {
        if(root==NULL) return ;

        queue<pair<TreeNode*,int>>q;
        q.push({root,0});

        while(!q.empty())
        {
            int sz=q.size();
            for(int i=0;i<sz;i++){
                TreeNode* node=q.front().first;
                int val=q.front().second;
                q.pop();
                
                freq[val]++;

                if(node->left) q.push({node->left,2*val+1});
                if(node->right) q.push({node->right,2*val+2});
            }
        }
    }
    FindElements(TreeNode* root) {
        
        bfs(root);
    }
    
    bool find(int target) {
        if(freq.find(target)!=freq.end()) return true;
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
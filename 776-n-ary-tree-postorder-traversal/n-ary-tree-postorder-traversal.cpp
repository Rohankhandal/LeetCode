/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void solve(Node *root,vector<int>&ans)
    {
        if(root==NULL) return ;
        for(auto &it:root->children)
        {
            solve(it,ans);
            ans.push_back(it->val);
        }
        
    }
    vector<int> postorder(Node* root) {
       if(root==NULL) return {} ;
        vector<int>ans;
        solve(root,ans);
       ans.push_back(root->val);  //insert root val
        return ans;
    }
};
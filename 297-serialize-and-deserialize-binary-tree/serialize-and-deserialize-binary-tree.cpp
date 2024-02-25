/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //Another method of doing is level order traversing
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        //Using preorder traversal 
        if(root==NULL) return "X";
        string leftSerialize=serialize(root->left);
        string rightSerialize=serialize(root->right);

        return to_string(root->val)+","+leftSerialize+","+rightSerialize;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        string s;
        queue<string>q;
        for(int i=0;i<data.size();i++)
        {
            if(data[i]==',')
            {
                q.push(s);
                s="";
                continue;
            }
            s+=data[i];
        }
        if(s.size()!=0) q.push(s);

        return deserialize_helper(q);
    }
    TreeNode* deserialize_helper(queue<string> &q)
    {
        string s=q.front();
        q.pop();
        if(s=="X") return NULL;
        TreeNode* root=new TreeNode(stoi(s));
        root->left=deserialize_helper(q);
        root->right=deserialize_helper(q);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
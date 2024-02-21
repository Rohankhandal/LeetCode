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

 //Iterative method using 2 stacks
// Solution 1: Using two stacks

// Approach: 

// The algorithm approach can be stated as:

// We take two explicit stacks S1 and S2.
// We insert our node to S1(if it’s not pointing to NULL).
// We will set up a while loop to run till S1 is non-empty.
// In every iteration, we pop out the top of S1 and then push this popped node to S2. Moreover we will push the left child and right child of this popped node to S1.(If they are not pointing to NULL).
// Then we start the next iteration with the next node as top of S1.
// We stop the iteration when S1 becomes empty.
// At last we start popping at the top of S2 and print the node values, we will get the postorder traversal.
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(!root) return ans;
        stack<TreeNode*>s1;
        stack<TreeNode*>s2;
        s1.push(root);
        while(!s1.empty())
        {
            TreeNode*top=s1.top();
            s1.pop();
            s2.push(top);
            if(top->left) s1.push(top->left);
            if(top->right) s1.push(top->right); 
        }

        //now pop all nodes from s2 and insert data in ans 
        while(!s2.empty())
        {
            ans.push_back((s2.top())->val);
            s2.pop();
        }
        return ans;
    }
};
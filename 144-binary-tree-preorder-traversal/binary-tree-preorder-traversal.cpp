/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
//Morris Traversal
//  Iterative Approach
// T.c:-O(N);
// S.c:_O(1);
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>preorder;
        TreeNode*curr=root;
        while(curr!=NULL)
        {
            if(curr->left==NULL)
            {
                preorder.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode*prev=curr->left;
                while(prev->right && prev->right!=curr)
                {
                    prev=prev->right;
                }

                if(prev->right==NULL)
                {
                    prev->right=curr;  //connect the right pointer
                    preorder.push_back(curr->val);  //IMP POINT
                    curr=curr->left;
                }
                else{
                    prev->right=NULL;  //when we again traverse same node , at that time 
                    //remove the right pointer , go to right side instead to left side
                    curr=curr->right;
                }
            }
        }
        return preorder;
    }
};

// //iterative Approach
// class Solution {
// public:

//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int>preOrder;
//         if(!root) return preOrder;
        
//         stack<TreeNode*>st;
//         st.push(root);
//         while(!st.empty())
//         {
//             TreeNode*top=st.top();
//             st.pop();
//             preOrder.push_back(top->val);
//             //first we push right node bcz at last left node is on top after both right and left , and we 
//             //have to acces top element on stack
//             if(top->right) st.push(top->right);  //if top right exist then insert in stack
//             if(top->left) st.push(top->left);
//         }
//         return preOrder;
//     }
// };




 //Recursive Appraoch
// class Solution {
// public:
// void helper(TreeNode*&root,vector<int>&ans)
// {
//     if(!root) return ;
//     ans.push_back(root->val);
//     helper(root->left,ans);
//     helper(root->right,ans);
// }
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int>ans;
//         helper(root,ans);
//         return ans;
//     }
// };
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
//Morris Traversal
//  Iterative Approach
// T.c:-O(N);
// S.c:_O(1);
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>inorder;
        TreeNode*curr=root;
        while(curr!=NULL)
        {
            if(curr->left==NULL)
            {
                inorder.push_back(curr->val);
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
                    curr=curr->left;
                }
                else{
                    prev->right=NULL;  //when we again traverse same node , at that time 
                    //remove the right pointer , go to right side instead to left side
                    inorder.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return inorder;
    }
};




// //  Iterative Approach
// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         stack<TreeNode*>st;
//         vector<int>inOrder;
//         TreeNode*node=root;
//         if(!root) return inOrder;
//         while(true)
//         {
//             if(node!=NULL)
//             {
//                 st.push(node);
//                 node=node->left;
//             }
//             else
//             {
//                 if(st.empty()==true) break;

//                 node=st.top();
//                 st.pop();
//                 inOrder.push_back(node->val);
//                 node=node->right;  //go to right
//             }
//         }
//         return inOrder;
//     }
// };
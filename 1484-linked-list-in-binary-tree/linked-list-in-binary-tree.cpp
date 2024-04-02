/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
// head =
// [2,2,1]
// root =
// [2,null,2,null,2,null,1] OUTPUT:-true

// head =
// [1,10]
// root =
// [1,null,1,10,1,9]     Output=>false

//  T.c:-O(N*height of Tree)
//  S.c:-(N)
class Solution {
public:
   bool isPath(ListNode* head, TreeNode* root){
        if(!head)
            return true;
        
        if(!root)
            return false;
        
        return (root->val == head->val) && (isPath(head->next, root->left) || isPath(head->next, root->right));
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root)
            return false;
        
        return (root->val == head->val && isPath(head, root)) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};
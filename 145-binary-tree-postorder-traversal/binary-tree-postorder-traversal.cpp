/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
//  Solution 2: Using a single stack:
// Time Complexity: O(2N).

// Space Complexity: O(N)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode*cur=root;
        vector<int> postOrder;
        if (cur == NULL)
            return postOrder;

        stack<TreeNode*> st;
        while (cur != NULL || !st.empty()) {

            if (cur != NULL) {
                st.push(cur);
                cur = cur->left;
            } else {
                TreeNode* temp = st.top()->right;
                if (temp == NULL) {
                    temp = st.top();
                    st.pop();
                    postOrder.push_back(temp->val);
                    while (!st.empty() && temp == st.top()->right) {
                        temp = st.top();
                        st.pop();
                        postOrder.push_back(temp->val);
                    }
                } else
                    cur = temp;
            }
        }
        return postOrder;
    }
};
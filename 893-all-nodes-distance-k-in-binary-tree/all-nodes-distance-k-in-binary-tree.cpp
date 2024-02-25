/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //IF GIVEEN TARGET IS NODE ,THEN ALL BELOW CODE IS CORRECT
//  1)mark parents pointer
//  2)move 1 distance to parent,left,right node , and increment distance by 1
//  3)also use one visited map which is use to mark the nodes which we visited
//  4)when distance is equal to k then, answer is sure in queue
class Solution {
public:
void markParent(TreeNode*root,unordered_map<TreeNode*,TreeNode*>&parent)
{
    if(!root) return;
        
        if(root->left)
            parent[root->left] = root;
        
        markParent(root->left,parent);
        
        if(root->right)
            parent[root->right] = root;
        
        markParent(root->right,parent);
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // Map to mark the parents of all nodes
        unordered_map<TreeNode*, TreeNode*> parent_track;
        // Mark parents of all nodes
        markParent(root, parent_track); 
        // Keeps track of visited nodes
        unordered_map<TreeNode*, bool> visited; 
        visited[target]=true;        //IMP POINT
        // Queue to perform level-order traversal
        queue<TreeNode*> q; 
         // Start traversal from the target node
        q.push(target);
        // Tracks the current level
        // while traversing the tree
        int curr_level = 0; 
        while(!q.empty())
        {
            // Get the number of nodes at the current level
            int size = q.size(); 
            if (curr_level++ == k) { 
                // Break if the current level
                // matches the required distance (k)
                break;
            }
            
            // Traverse the current level of the tree
            for (int i = 0; i < size; i++) {
                // Get the front node in the queue
                TreeNode* current = q.front(); 
                // Remove the front node from the queue
                q.pop(); 
                
                // Add unvisited left child to the queue
                if (current->left && !visited[current->left]) {
                    q.push(current->left);
                    // Mark left child as visited
                    visited[current->left] = true; 
                }
                
                // Add unvisited right child to the queue
                if (current->right && !visited[current->right]) {
                    q.push(current->right);
                     // Mark right child as visited
                    visited[current->right] = true;
                }
                
                // Add unvisited parent node to the queue
                if (parent_track[current] && !visited[parent_track[current]]) {
                    q.push(parent_track[current]);
                    // Mark parent node as visited
                    visited[parent_track[current]] = true; 
                }
            }
        }

        // Stores nodes at distance k from the target
        vector<int> result; 
        while (!q.empty()) { 
            // Extract nodes at distance k from the queue
            TreeNode* current = q.front();
            q.pop();
            // Store node values in the result vector
            result.push_back(current->val); 
        }

        
        // Return nodes at distance
        // K from the target
        return result; 

    }
};
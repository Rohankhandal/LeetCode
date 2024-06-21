class Solution {
public:
    // Perform topological sorting using Kahn's algorithm
    bool topologicalSort(vector<int>& indegree, unordered_map<int, vector<int>>& adj, int n) {
        queue<int> que; // Queue to process nodes with zero indegree
        int count = 0; // Count of nodes processed

        // Add all nodes with zero indegree to the queue
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                count++;
                que.push(i);
            }
        }

        // Process nodes in the queue
        while (!que.empty()) {
            int u = que.front();
            que.pop();

            // Visit all adjacent nodes of 'u'
            for (int& v : adj[u]) {
                indegree[v]--; // Decrement indegree of node 'v'
                
                // If indegree of 'v' becomes zero, add it to the queue
                if (indegree[v] == 0) {
                    count++;
                    que.push(v);
                }
            }
        }

        // If all nodes were processed, return true (no cycle)
        if (count == n) {
            return true; // All courses can be finished
        }

        return false; // There was a cycle, so not all courses can be finished
    }

    // Function to check if all courses can be finished given the prerequisites
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj; // Adjacency list
        vector<int> indegree(numCourses, 0); // Indegree array

        // Build the graph and indegree array from the prerequisites
        for (auto& vec : prerequisites) {
            int a = vec[0];
            int b = vec[1];

            // Edge b -> a (a depends on b)
            adj[b].push_back(a);
            indegree[a]++;
        }

        // Perform topological sort and check if all courses can be finished
        return topologicalSort(indegree, adj, numCourses);
    }
};

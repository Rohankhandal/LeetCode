class Solution {
public:
    // Perform topological sorting using Kahn's algorithm
    vector<int> topologicalSort(int n, vector<int>& indegree, unordered_map<int, vector<int>>& adj) {
        queue<int> q; // Queue to process nodes with zero indegree
        vector<int> ans; // Vector to store the topological order
        int count = 0; // Count of nodes processed

        // Add all nodes with zero indegree to the queue
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                ans.push_back(i);
                count++;
                q.push(i);
            }
        }

        // Process nodes in the queue
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            // Visit all adjacent nodes of 'u'
            for (int& v : adj[u]) {
                indegree[v]--; // Decrement indegree of node 'v'
                
                // If indegree of 'v' becomes zero, add it to the queue
                if (indegree[v] == 0) {
                    ans.push_back(v);
                    count++;
                    q.push(v);
                }
            }
        }

        // If all nodes were processed, return the topological order
        if (count == n) {
            return ans;
        }

        // If there was a cycle, return an empty vector
        return {};
    }

    // Function to find the order in which courses should be taken
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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

        // Perform topological sort and return the order of courses
        return topologicalSort(numCourses, indegree, adj);
    }
};

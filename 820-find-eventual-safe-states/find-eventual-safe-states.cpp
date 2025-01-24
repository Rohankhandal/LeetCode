class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ans;
        unordered_map<int, vector<int>> reverseGraph;
        vector<int> outDegree(n, 0); // Out-degree for each node

        // Build reverse graph and calculate out-degree
        for (int i = 0; i < n; i++) {
            for (int neighbor : graph[i]) {
                reverseGraph[neighbor].push_back(i);
                outDegree[i]++;
            }
        }

        // Queue for processing nodes with no outgoing edges (safe nodes)
        queue<int> q;
        vector<bool> visited(n, false); // Track processed nodes

        // Add nodes with no outgoing edges to the queue
        for (int i = 0; i < n; i++) {
            if (outDegree[i] == 0) {
                q.push(i);
                visited[i] = true;
            }
        }

        // Process the nodes
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            // Reverse process neighbors in the reverse graph
            for (int neighbor : reverseGraph[node]) {
                if (--outDegree[neighbor] == 0) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }

        // Sort the result to return the safe nodes in ascending order
        sort(ans.begin(), ans.end());
        return ans;
    }
};

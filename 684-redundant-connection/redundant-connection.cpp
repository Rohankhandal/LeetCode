class Solution {
public:
    bool isTree(int n, vector<vector<int>>& edges, int skipEdge) {
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < edges.size(); i++) {
            if (i == skipEdge)
                continue; // Skip the edge under consideration
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        // DFS to check if the graph is connected and acyclic
        unordered_set<int> visited;
        vector<int> stack = {1}; // Start DFS from node 1
        visited.insert(1);

        while (!stack.empty()) {
            int node = stack.back();
            stack.pop_back();
            for (int neighbor : adj[node]) {
                if (visited.count(neighbor))
                    continue; // Ignore visited nodes
                visited.insert(neighbor);
                stack.push_back(neighbor);
            }
        }

       
        return visited.size() == n;
    }


    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        for (int i = n - 1; i >= 0; i--) { // Check edges in reverse order
            if (isTree(n, edges, i)) {
                return edges[i];
            }
        }

        return {};
    }
};
// **S-1:**
// Find best level count in TREE-2:
// max(E2, O2) => best2

// **S-2:**
// Mark nodes at E & O levels in TREE-1.
// Also count nodes at even levels in TREE-1.

// **S-3:**
// Iterate for each node in TREE-1.
// If node is at even level:
// res = E1 + best2
// Else:
// res = (N - E1) + best2

class Solution {
public:
    // Returns count of even-level nodes and a parity map for each node (true = even, false = odd)
    pair<int, vector<bool>> getParityInfo(const vector<vector<int>>& adj) {
        int n = adj.size();
        vector<bool> visited(n, false), parity(n);
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0] = true;

        int evenCount = 0;
        while (!q.empty()) {
            auto [node, level] = q.front(); q.pop();
            parity[node] = (level % 2 == 0);
            if (parity[node]) evenCount++;

            for (int nei : adj[node]) {
                if (!visited[nei]) {
                    visited[nei] = true;
                    q.push({nei, level + 1});
                }
            }
        }
        return {evenCount, parity};
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<vector<int>> adj1(n), adj2(m);

        for (auto& e : edges1) {
            adj1[e[0]].push_back(e[1]);
            adj1[e[1]].push_back(e[0]);
        }
        for (auto& e : edges2) {
            adj2[e[0]].push_back(e[1]);
            adj2[e[1]].push_back(e[0]);
        }

        auto [even1, parity1] = getParityInfo(adj1);
        int even2 = getParityInfo(adj2).first;
        int best2 = max(even2, m - even2);

        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            res[i] = (parity1[i] ? even1 : n - even1) + best2;
        }
        return res;
    }
};

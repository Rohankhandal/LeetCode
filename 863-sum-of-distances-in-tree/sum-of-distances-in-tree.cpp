class Solution {
public:
    vector<int> count;
    int baseCount;
    int N;

    int dfs(unordered_map<int, vector<int>>& adj, int src, int parent, int curr_depth) {
        int total = 1;
        baseCount += curr_depth;

        for (auto& v : adj[src]) {
            if (v != parent) {
                total += dfs(adj, v, src, curr_depth + 1);
            }
        }

        count[src] = total;
        return total;
    }

    void dfs2(unordered_map<int, vector<int>>& adj, int src, int parent, vector<int>& ans) {
        for (auto& v : adj[src]) {
            if (v != parent) {
                ans[v] = ans[src] - count[v] + (N - count[v]);
                dfs2(adj, v, src, ans);
            }
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        N = n;
        baseCount = 0;
        count.resize(n, 0);

        dfs(adj, 0, -1, 0);  // Build subtree sizes and root distances

        vector<int> ans(n, 0);
        ans[0] = baseCount;
        dfs2(adj, 0, -1, ans);  // Propagate distances

        return ans;
    }
};

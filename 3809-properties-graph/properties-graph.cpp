class Solution {
public:
    int intersect(vector<int> &a, vector<int> &b) {
        int i = 0, j = 0, cnt = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) cnt++, i++, j++;
            else if (a[i] < b[j]) i++;
            else j++;
        }
        return cnt;
    }
    
    void dfs(int u, vector<int> &vis, vector<vector<int>> &adj) {
        vis[u] = 1;
        for (int v : adj[u]) {
            if (vis[v]) continue;
            dfs(v, vis, adj);
        }
    }
    
    int numberOfComponents(vector<vector<int>>& prop, int k) {
        int n = prop.size();
        for (int i = 0; i < n; i++) {
            sort(prop[i].begin(), prop[i].end());
            prop[i].resize(unique(prop[i].begin(), prop[i].end()) - prop[i].begin());
        }
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int cnt = intersect(prop[i], prop[j]);
                if (cnt >= k) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int ans = 0;
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            dfs(i, vis, adj);
            ans++;
        }
        return ans;
    }
};
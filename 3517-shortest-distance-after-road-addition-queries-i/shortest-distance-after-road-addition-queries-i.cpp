class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<n-1;i++)
        {
            adj[i].push_back(i+1);
        }

        
        auto shortestPath = [&](int start, int end) {
            vector<int> dist(n, INT_MAX);
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
            dist[start] = 0;
            pq.push({0, start});
            
            while (!pq.empty()) {
                auto [d, u] = pq.top();
                pq.pop();
                
                for (auto &v : adj[u]) {
                    int adjNode=v;
                    if (1 + d < dist[v]) {
                        dist[v] = dist[u] + 1;
                        pq.push({dist[v], v});
                    }
                }
            }
            
            return dist[end];
        };

        vector<int> ans;
    
        for (auto& q : queries) {
            int u = q[0];
            int v = q[1];
            adj[u].push_back(v);
            ans.push_back(shortestPath(0, n - 1));
        }
        
        return ans;
    }
};
class Solution {
public:
    int M = 1e9 + 7;

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<int> ways(n, 0);
        vector<long long> dist(n, LLONG_MAX);  // Change to long long
        unordered_map<int, vector<pair<int, int>>> adj;

        for (auto &it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
        q.push({0, 0});  // {distance, node}
        dist[0] = 0;
        ways[0] = 1;

        while (!q.empty()) {
            int u = q.top().second;
            long long dis = q.top().first;  // Change to long long
            q.pop();

            for (auto &it : adj[u]) {
                int adjNode = it.first;
                int d = it.second;

                if (dis + d < dist[adjNode]) {
                    // Found a shorter path
                    ways[adjNode] = ways[u];
                    dist[adjNode] = dis + d;
                    q.push({dist[adjNode], adjNode});
                } else if (dis + d == dist[adjNode]) {
                    // Found another path with the same shortest distance
                    ways[adjNode] = (ways[adjNode] + ways[u]) % M;
                }
            }
        }

        return ways[n-1] % M;
    }
};

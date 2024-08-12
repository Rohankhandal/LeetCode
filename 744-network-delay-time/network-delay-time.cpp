class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        // Create an adjacency list to represent the graph
        unordered_map<int, vector<pair<int, int>>> adj;
        for(auto &vec : times) {
            int u = vec[0];  // Source node
            int v = vec[1];  // Destination node
            int w = vec[2];  // Weight (time) of the edge
            adj[u].push_back({v, w});
        }
        
        // Min-heap priority queue to store (distance, node)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Initialize result vector to store the shortest time to reach each node
        vector<int> result(n + 1, INT_MAX);
        result[k] = 0;  // Starting node has a distance of 0
        pq.push({0, k});  // Push the starting node into the priority queue

        // Implementing Dijkstra's algorithm
        while(!pq.empty()) {
            int d  = pq.top().first;  // Current distance
            int node = pq.top().second;  // Current node
            pq.pop();

            // Iterate over all adjacent nodes
            for(auto &vec : adj[node]) {
                int adjNode = vec.first;  // Adjacent node
                int dist    = vec.second;  // Distance to adjacent node

                // Relaxation step: check if a shorter path is found
                if(d + dist < result[adjNode]) {
                    result[adjNode] = d + dist;  // Update with the shorter distance
                    pq.push({d + dist, adjNode});  // Push the updated distance into the priority queue
                }
            }
        }
        
        int ans = INT_MIN;
        
        // Find the maximum time among the shortest times to each node
        for(int i = 1; i <= n; i++)
            ans = max(ans, result[i]);
        
        // If any node is unreachable, return -1
        return ans == INT_MAX ? -1 : ans;
    }
};

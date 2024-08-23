class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int Threshold) {
        // Adjacency list to store the graph: adj[node] = {{neighbor1, weight1}, {neighbor2, weight2}, ...}
        vector<vector<vector<int>>> adj(n);

        // Building the graph from the given edges
        for (auto x : edges) {
            adj[x[0]].push_back({x[1], x[2]});
            adj[x[1]].push_back({x[0], x[2]});
        }

        int minReachCity = -1;  // City with the minimum reachable cities
        int minReach = INT_MAX; // Minimum number of reachable cities

        // Iterate over each city as the starting point
        for (int S = 0; S < n; S++) {
            // Min-heap priority queue for Dijkstra's algorithm
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
            vector<int> dis(n, INT_MAX); // Distance vector initialized to infinity

            // Starting city has a distance of 0
            dis[S] = 0;
            pq.push({0, S});

            // Dijkstra's algorithm to calculate shortest paths from city S
            while (!pq.empty()) {
                int node = pq.top().second;
                pq.pop();

                for (auto x : adj[node]) {
                    int adjNode = x[0];
                    int edgeWeight = x[1];

                    // Relaxation step: Update the shortest distance to adjNode
                    if (dis[adjNode] > (dis[node] + edgeWeight)) {
                        dis[adjNode] = dis[node] + edgeWeight;
                        pq.push({dis[adjNode], adjNode});
                    }
                }
            }

            int reach = 0; // Count the number of reachable cities within the Threshold

            // Count cities reachable from city S within the threshold distance
            for (auto x : dis) {
                if (x <= Threshold) reach++;
            }

            // Update the city with the minimum reachability
            if (reach <= minReach) {
                // If reach is the same as minReach, choose the city with the larger index
                minReachCity = (reach == minReach) ? max(minReachCity, S) : S;
                minReach = reach;
            }
        }

        return minReachCity; // Return the city with the fewest reachable cities
    }
};

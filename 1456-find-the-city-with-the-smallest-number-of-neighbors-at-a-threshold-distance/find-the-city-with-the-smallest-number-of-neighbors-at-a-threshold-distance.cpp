class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int Threshold) {
        vector<vector<vector<int>>> adj(n);

        for(auto x : edges) {
            adj[x[0]].push_back({x[1], x[2]});
            adj[x[1]].push_back({x[0], x[2]});
        }

        int minReachCity = -1;
        int minReach = INT_MAX;

        for(int S=0; S<n; S++) {
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
            vector<int> dis(n, INT_MAX);
            
            dis[S] = 0;
            pq.push({0,S});
            
            while(!pq.empty()) {
                int node = pq.top().second;
                pq.pop();
                for(auto x : adj[node]) {
                    int adjNode = x[0];
                    int edgeWeight = x[1];
                    if(dis[adjNode] > (dis[node] + edgeWeight)) {
                        dis[adjNode] = dis[node] + edgeWeight;
                        pq.push({dis[adjNode], adjNode});
                    }
                }
            }

            int reach = 0;

            for(auto x : dis) {
                if(x <= Threshold) reach++;
            }

            if(reach <= minReach) {
                minReachCity = (reach == minReach) ? max(minReachCity, S) : S;
                minReach = reach;
            }
        }

        return minReachCity;
    }
};
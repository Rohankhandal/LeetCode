//Approach-1 (Using BFS)
//T.C : O(log(maxWt) * (V+E))
//S.C : O(V+E)
class Solution {
public:
    typedef pair<int, int> P;

    bool canAllReachZero(int n, unordered_map<int, vector<P>>& adj, int mid) {
        //BFS
        queue<int> que;
        vector<bool> visited(n, false);

        que.push(0);
        visited[0] = true;

        while(!que.empty()) {
            int u = que.front();
            que.pop();

            for(P &p : adj[u]) {
                int v = p.first; //ngbr node
                int w = p.second;  //edge weight

                if(w <= mid && !visited[v]) {
                    visited[v] = true;
                    que.push(v);
                }
            }
        }

        for(int i = 0; i < n; i++) {
            if(visited[i] == false) { //this ith node was not visited
                return false; //we could not visit all the nodes
            }
        }

        return true;
    }

    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        unordered_map<int, vector<P>> adj;
        // u -> {(v1, w1), (v2,w2),... }

        int maxWt = 0;
        //Form the adj with reversed edge
        for(vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[v].push_back({u, w}); //with reversed edge
            maxWt = max(maxWt, w);
        }

        //apply binary search on answer (weight)
        int result = INT_MAX; //invalid answer

        int l = 0;
        int r = maxWt;

        while(l <= r) {
            int mid = l + (r-l)/2;

            if(canAllReachZero(n, adj, mid) == true) {
                result = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        return result == INT_MAX ? -1 : result;

    }
};


// //Approach-2 (Using DFS)
// //T.C : O(log(maxWt) * (V+E))
// //S.C : O(V+E)
// class Solution {
// public:
    
//     typedef pair<int, int> P;

//     void dfs(int u, unordered_map<int, vector<P>>& adj, int mid, vector<bool>& visited) {
//         visited[u] = true;

//         //visit all ngbrs of u if possible
//         for(auto &p : adj[u]) {
//             int v = p.first;
//             int w = p.second;

//             if(w <= mid && !visited[v]) {
//                 visited[v] = true;
//                 dfs(v, adj, mid, visited);
//             }
//         }
//     }

//     bool canAllReachZero(int n, unordered_map<int, vector<P>>& adj, int mid) {
//         //DFS
//         vector<bool> visited(n, false);
//         dfs(0, adj, mid, visited);

//         for(int i = 0; i < n; i++) {
//             if(visited[i] == false) {
//                 return false;
//             }
//         }

//         return true;
//     }

//     int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
//         unordered_map<int, vector<P>> adj;
//         // u -> {(v1, w1), (v2,w2),... }

//         int maxWt = 0;
//         //Form the adj with reversed edge
//         for(vector<int>& edge : edges) {
//             int u = edge[0];
//             int v = edge[1];
//             int w = edge[2];

//             adj[v].push_back({u, w}); //with reversed edge
//             maxWt = max(maxWt, w);
//         }

//         //apply binary search on answer (weight)
//         int result = INT_MAX; //invalid answer

//         int l = 0;
//         int r = maxWt;
        
//         //T.C : O(log(maxWt) * (V+E))
//         //S.C : O(V+E)
//         while(l <= r) {
//             int mid = l + (r-l)/2;

//             if(canAllReachZero(n, adj, mid) == true) { //O(V+E) due to BFS or DFS
//                 result = mid;
//                 r = mid-1;
//             } else {
//                 l = mid+1;
//             }
//         }

//         return result == INT_MAX ? -1 : result;

//     }
// };
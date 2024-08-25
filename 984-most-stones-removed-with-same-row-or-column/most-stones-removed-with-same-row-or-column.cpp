class DisjointSet {
    vector<int> rank, parent, size;
public:
    // Constructor to initialize the Disjoint Set data structure
    DisjointSet(int n) {
        rank.resize(n + 1, 0);  // Initialize rank for each node
        parent.resize(n + 1);  // Initialize parent for each node
        size.resize(n + 1);  // Initialize size for each component
        for (int i = 0; i <= n; i++) {
            parent[i] = i;  // Each node is its own parent initially
            size[i] = 1;  // Each component has size 1 initially
        }
    }

    // Function to find the ultimate parent of a node with path compression
    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);  // Path compression
    }

    // Function to union two nodes by rank
    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);  // Find ultimate parent of u
        int ulp_v = findUPar(v);  // Find ultimate parent of v
        if (ulp_u == ulp_v) return;  // If they are already in the same set, do nothing

        // Union by rank logic
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    // Function to union two nodes by size
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);  // Find ultimate parent of u
        int ulp_v = findUPar(v);  // Find ultimate parent of v
        if (ulp_u == ulp_v) return;  // If they are already in the same set, do nothing

        // Union by size logic
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];  // Update size of the new root
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];  // Update size of the new root
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow = 0;
        int maxCol = 0;

        // Find the maximum row and column indices
        for (auto it : stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        // Initialize Disjoint Set to handle all row and column indices
        DisjointSet ds(maxRow + maxCol + 1);

        // Map to track the nodes that represent the stones
        unordered_map<int, int> stoneNodes;

        // Union all stones in the same row or column
        for (auto it : stones) {
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;  // Offset columns to avoid collision with rows
            ds.unionBySize(nodeRow, nodeCol);  // Union the row and column
            stoneNodes[nodeRow] = 1;  // Mark the row node
            stoneNodes[nodeCol] = 1;  // Mark the column node
        }

        // Count the number of connected components
        int cnt = 0;
        for (auto it : stoneNodes) {
            if (ds.findUPar(it.first) == it.first) {
                cnt++;  // If a node is its own parent, it represents a unique component
            }
        }

        // The maximum number of stones that can be removed is the total stones minus the number of components
        return n - cnt;
    }
};

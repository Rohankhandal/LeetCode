class Solution {
public:
    vector<int> parent;  // Stores parent of each node
    vector<int> rank;    // Stores rank of each set for union by rank

    // Find operation with path compression
    int find(int x) {
        if (x == parent[x]) 
            return x;
        return parent[x] = find(parent[x]);
    }

    // Union operation with rank
    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
        if (x_parent == y_parent) 
            return;
        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        // Check if there are enough cables
        if (connections.size() < n-1)
            return -1;
        
        // Initialize parent and rank vectors
        parent.resize(n);
        rank.resize(n, 0);
        
        for (int i = 0; i < n; i++)
            parent[i] = i;
        
        int components = n;  // Start with n components
        for (auto &vec : connections) {
            if (find(vec[0]) != find(vec[1])) {
                components--;  // Decrease component count when connecting two separate components
                Union(vec[0], vec[1]);
            }
        }
        return components - 1;  // Return number of operations needed to connect all components
    }
};
#include <vector>
using namespace std;

class Solution {
public:
    long long totalFuel = 0;

    // DFS function to compute representatives and accumulate fuel
    int dfs(int node, int parent, vector<vector<int>>& adj, int seats) {
        int representatives = 1; // Count the current city

        for(auto &child : adj[node]) {
            if(child == parent) continue; // Skip the parent to avoid revisiting
            representatives += dfs(child, node, adj, seats); // Aggregate representatives from child
        }

        if(node != 0) { // If not the capital, calculate fuel
            // Calculate the number of trips needed
            long long trips = (representatives + seats - 1) / seats;
            totalFuel += trips; // Each trip consumes 1 liter per road segment
        }

        return representatives;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1; // Number of cities
        vector<vector<int>> adj(n, vector<int>()); // Adjacency list

        // Build the adjacency list
        for(auto &road : roads) {
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
        }

        // Perform DFS starting from the capital (node 0)
        dfs(0, -1, adj, seats);

        return totalFuel;
    }
};

//Approach-1 (Using DFS)
//T.C : O(n * (n+m)) , n = number of vertices and m = number of edges
//S.C : O(n+m)
class Solution {
public:
    void DFS(int ancestor, unordered_map<int, vector<int>>& adj, int currNode, vector<vector<int>>& result) {

        for(int &ngbr : adj[currNode]) {
            if(result[ngbr].empty() || result[ngbr].back() != ancestor) { //to avoid duplicate entry
                result[ngbr].push_back(ancestor);
                DFS(ancestor, adj, ngbr, result);  //IMP
            }
        }

    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> result(n);
        unordered_map<int, vector<int>> adj;

        for(vector<int>& vec : edges) {
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v); //u --> v
        }


        for(int i = 0; i < n; i++) {
            int ancestor = i;
            DFS(ancestor, adj, i, result);
        }

        return result;
    }
};
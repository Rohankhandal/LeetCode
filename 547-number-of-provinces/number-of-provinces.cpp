//DFS

// class Solution {
// public:
//     void dfs(unordered_map<int,bool>&visited,int src,vector<vector<int>>& isConnected)
//     {
//         visited[src]=true;
//         int size=isConnected.size();
//         for(int col=0;col<size;col++ )
//         {
//             //edge present or notdd
//             if(isConnected[src][col]==1)
//             {
//                 if(!visited[col])
//                 {
//                     dfs(visited,col,isConnected);
//                 }
//             }
//         }
//     }
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int n=isConnected.size();
//         int m=isConnected[0].size();

//         unordered_map<int,bool>visited;

//         int count=0;
//         for(int i=0;i<n;i++)
//         {
//             if(!visited[i])
//             {
//                 dfs(visited,i,isConnected);
//                 count++;
//             }
//         }
//         return count;
//     }
// };


//BFS
class Solution {
public:
    // Perform BFS starting from the source node 'src'
    void bfs(int src, unordered_map<int, bool>& visited, vector<vector<int>>& isConnected) {
        // Mark the source node as visited
        visited[src] = true;

        // Initialize a queue for BFS
        queue<int> q;
        q.push(src);

        // Process nodes in the queue
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            // Visit all adjacent nodes of 'u'
            for (int v = 0; v < isConnected.size(); v++) {
                // If there is a connection and the node 'v' is not visited
                if (isConnected[u][v] == 1 && !visited[v]) {
                    q.push(v);
                    visited[v] = true; // Mark node 'v' as visited
                }
            }
        }
    }

    // Function to find the number of connected components (provinces) in the graph
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(); // Number of nodes (cities)
        unordered_map<int, bool> visited; // Map to keep track of visited nodes

        int count = 0; // Initialize count of provinces

        // Iterate over all nodes
        for (int i = 0; i < n; i++) {
            // If the node 'i' is not visited, it means we have found a new province
            if (!visited[i]) {
                bfs(i, visited, isConnected); // Perform BFS starting from node 'i'
                count++; // Increment the count of provinces
            }
        }

        // Return the total number of provinces
        return count;
    }
};

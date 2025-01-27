class Solution {
public:
    bool bfs(int src,int dest,unordered_map<int,vector<int>>&mp,int n)
    {
        queue<int> q;
        vector<bool> visited(n, false);

        q.push(src);
        visited[src] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (node == dest) return true;;

            for (int neighbor : mp[node]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
        return false;
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>>mp;
        for(auto &it:prerequisites)
        {
            int u=it[0];
            int v=it[1];
            mp[u].push_back(v);
        }

        vector<vector<bool>>isReach(n,vector<bool>(n,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j) continue;
                if(bfs(i,j,mp,n))
                {
                    isReach[i][j]=true;
                }
            }
        }
        vector<bool>ans;
        for(auto &it:queries){
            int i=it[0];
            int j=it[1];
            if(isReach[i][j])
            {
                ans.push_back(true);
            }
            else ans.push_back(false);
        }
        return ans;
    }
};
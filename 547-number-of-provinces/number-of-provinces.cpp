class Solution {
public:
    void dfs(unordered_map<int,vector<int>>&adj,vector<bool>&visited,int src)
    {
        visited[src]=true;

        for(auto &it:adj[src])
        {
            if(!visited[it])
            {
                dfs(adj,visited,it);
            }
        }
    }

    void bfs(unordered_map<int,vector<int>>&adj,vector<bool>&visited,int src)
    {
        queue<int>q;
        q.push(src);
        visited[src]=true;

        while(!q.empty())
        {
            int val=q.front();
            q.pop();
            for(auto &it:adj[val])
            {
                if(!visited[it])
                {
                    visited[it]=true;
                    q.push(it);
                }
            }
        }

    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n=isConnected.size();
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<n;i++)
        {
            int m=isConnected.size();
            for(int j=0;j<m;j++)
            {
                if(isConnected[i][j]==1 && i!=j)
                 adj[i].push_back(j);
            }
        }

        vector<bool>visited(n,false);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!visited[i])
            {
                // dfs(adj,visited,i);
                bfs(adj,visited,i);

                ans++;
            }
        }
        return ans;
    }
};
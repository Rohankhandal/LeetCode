class Solution {
public:
    void dfs(unordered_map<int,vector<int>>&mp,vector<bool>&visited,int src)
    {
        visited[src]=true;

        for(auto &it:mp[src])
        {
            if(!visited[it])
            {
                dfs(mp,visited,it);
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
                dfs(adj,visited,i);
                ans++;
            }
        }
        return ans;
    }
};
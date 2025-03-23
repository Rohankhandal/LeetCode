class Solution {
public:
    int M=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto &r:roads)
        {
            int u=r[0];
            int v=r[1];
            int wt=r[2];

            adj[u].push_back({wt,v});
            adj[v].push_back({wt,u});
        }

        vector<long long>dist(n,LLONG_MAX);
        vector<int>ways(n,0);
        
        dist[0]=0;
        ways[0]=1;
        priority_queue<pair<long long ,int>,vector<pair<long long ,int>>,greater<pair<long long ,int>>>pq;
        pq.push({0,0});
        while(!pq.empty())
        {
            long long  wt=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            for(auto &it:adj[node])
            {
                long long  d=it.first;
                int v=it.second;
                if((d+wt)<dist[v])
                {
                    dist[v]=d+wt;
                    ways[v]=ways[node];
                    pq.push({dist[v],v});
                }
                else if(d+wt==dist[v])
                {
                    ways[v]=(ways[v]+ways[node])%M;
                }
            }
        }
        return ways[n-1]%M;
    }
};
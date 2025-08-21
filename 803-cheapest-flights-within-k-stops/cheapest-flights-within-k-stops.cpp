class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto &f:flights)
        {
            adj[f[0]].push_back({f[1],f[2]});
        }

        vector<int>dist(n,INT_MAX);
        queue<vector<int>>q;
        //cost,node;
        q.push({src,0});
        dist[src]=0;

        while(!q.empty() && k>=0){
            int sz=q.size();

            while(sz--)
            {
                int u=q.front()[0];
                int cost=q.front()[1];
                q.pop();
                
                for(auto &it:adj[u]){
                    int v=it.first;
                    int d=it.second;
                    
                    if((d+cost)<dist[v]){
                        dist[v]=(d+cost);
                        q.push({v,dist[v]});
                    }
                }
            }
            k--;
        }

        return dist[dst]==INT_MAX?-1:dist[dst];

    }
};
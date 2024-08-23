

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto &it:edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        int maxReachCity=-1;
        int minSize=INT_MAX;
        for(int src=0;src<n;src++)
        {
            vector<int>dist(n,INT_MAX);
            queue<pair<int,int>>q;
            q.push({0,src});  //dist,node
            dist[src]=0;

            while(!q.empty())
            {
                int u=q.front().second;
                int d=q.front().first;
                q.pop();

                for(auto &v:adj[u])
                {
                    int dis=v.second;
                    int adjNode=v.first;

                    if(d+dis<dist[adjNode])
                    {
                        dist[adjNode]=d+dis;
                        q.push({dist[adjNode],adjNode});
                    }
                }
            }

            int count=0;
            for(auto &it:dist)
            {
                if(it<=distanceThreshold)
                {
                    count++;
                }
            }
            cout<<src<<" "<<count<<endl;

            if(minSize>count)
            {
                minSize=count;
                maxReachCity=src;
            }
             if(minSize==count)
            {
                maxReachCity=max(maxReachCity,src);
            }
        }
        return maxReachCity;
    }
};
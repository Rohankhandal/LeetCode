class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto &it:times)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }

        vector<int>dis(n+1,INT_MAX);

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dis[k]=0;
        pq.push({0,k});  //insert src node

        while(!pq.empty())
        {
            int d=pq.top().first;
            int node=pq.top().second;

            pq.pop();

            for(auto &adjNode:adj[node])
            {
                int neighbour=adjNode.first;
                int distance=adjNode.second;
                if(d+distance < dis[neighbour])
                {
                    dis[neighbour]=d+distance;
                    pq.push({dis[neighbour],neighbour});
                }
            }
        }
        // for(int i=1;i<=n;i++)
        // {
        //     cout<<dis[i]<<endl;
        // }
        int ans=-1;
        for(int i=1;i<=n;i++)
        {
            if(dis[i]==INT_MAX) return -1;
            ans=max(dis[i],ans);
        }
        return ans;


    }
};
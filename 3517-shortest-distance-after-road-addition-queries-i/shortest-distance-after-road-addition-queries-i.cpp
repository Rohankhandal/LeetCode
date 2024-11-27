class Solution {
public:
    int findShortestPath(int src,int des,unordered_map<int,vector<int>>&adj)
    {
        int n=des+1;
        vector<int>minDis(n,INT_MAX);
        // vector<bool>visited(n,false);l

         queue<int> pq;
        pq.push(src);
        minDis[src] = 0;
        while(!pq.empty())
        {
            int u=pq.front();
            pq.pop();

            for(auto &v:adj[u])
            {
                if(minDis[u]+1<minDis[v])
                {
                    minDis[v]=minDis[u]+1;
                    pq.push(v);
                }
            }
            

        }

        return (minDis[des] == INT_MAX) ? -1 : minDis[des];
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int>ans;
        unordered_map<int,vector<int>>adj;
       
        for(int i=0;i<n-1;i++)
        {
            adj[i].push_back(i+1);
        }
    
        for(auto &q:queries)
        {
            int u=q[0];
            int v=q[1];
             
            adj[u].push_back(v);
            int res=findShortestPath(0,n-1,adj);
            ans.push_back(res);
        }

        return ans;
    }
};
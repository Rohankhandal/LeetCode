class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int,vector<pair<int,double>>>adj;
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            double wt=succProb[i];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        vector<double>dist(n,INT_MIN);
        priority_queue<pair<double,double>>pq;
        pq.push({1,start_node});  //distance,node    //yahi galati hogi (starting probability is 1)

        while(!pq.empty())
        {
            double dis=pq.top().first;
            int node=pq.top().second;

            pq.pop();
            for(auto &v:adj[node])
            {
                int adjNode=v.first;
                double d=v.second;
                if((dis*d)>dist[adjNode])
                {
                    dist[adjNode]=dis*d;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        return dist[end_node]==INT_MIN?0:dist[end_node];
        
    }
};
class Solution {
public:
    typedef pair<int,int> P;
    const int LARGE_VALUE=2*1e9;
    int shortestPath(int n,unordered_map<int,vector<pair<int,int>>>&adj,int src,int dest,int target)
    {
        priority_queue<P,vector<P>,greater<P>>pq;

        pq.push({0,src});
        vector<int>distance(n,INT_MAX);
        distance[src]=0;

        while(!pq.empty())
        {
            int d=pq.top().first;
            int u=pq.top().second;
            pq.pop();

            for(auto &it:adj[u])
            {
                int v=it.first;
                int wt=it.second;

                if(d+wt<distance[v])
                {
                    distance[v]=d+wt;
                    pq.push({distance[v],v});
                }
            }
        }
        // for(int i=0;i<n;i++)
        // {
        //     cout<<i<<" "<<distance[i]<<endl;
        // }
        return distance[dest];
    }
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto &it:edges)
        {
            
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            if(wt!=-1)
            {
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
            }
        }   
        int lastDist=shortestPath(n,adj,source,destination,target);
        
        vector<vector<int>>ans=edges;

        //case 1: 
        if(lastDist<target)
        {
            return {};
        }
        else if(lastDist==target)
        {
            for(auto &it:ans)
            {
                if(it[2]==-1)
                {
                    it[2]=LARGE_VALUE;
                }
            }
            return ans;
        }
        
        
        //initially assign weight=1 , one by one to all negative weights and check shortest path
        //1)if Shortest path is still greater than target , update next negative weight edge , and so on.
        //2)when shortest path is less than or equal to target, at that time 
        //assign (target - shortest path) value to last updated weight. so that, shortest path is equal to target

        //recalculate the shortest path
        for(auto &it:ans)
        {
            int u=it[0];
            int v=it[1];
            int &wt=it[2];

            if(wt==-1)
            {
                wt=1;
                //change the weight to 1
                adj[u].push_back({v,1});
                adj[v].push_back({u,1});


                //now check shortest path
                lastDist=shortestPath(n,adj,source,destination,target);

                if(lastDist>target)
                {
                    continue;
                }
                else
                {
                    if(target>lastDist)
                        wt+=(target-lastDist);   //yahi galati hogi (add karna ha extra distance ko)
                    for(auto &it:ans)
                    {
                        if(it[2]==-1)
                        {
                            it[2]=LARGE_VALUE;
                        }
                    }
                    return ans;
                }
            }
        }
        return {};
    }
};
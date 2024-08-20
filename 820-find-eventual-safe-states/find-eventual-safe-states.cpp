class Solution {
public:
    vector<int> topologicalSort( unordered_map<int,vector<int>>&adj,vector<int>&inDegree,int V)
    {
        queue<int>q;
        vector<int>ans;
        for(int i=0;i<V;i++)
        {
            if(inDegree[i]==0)
            q.push(i);
        }

        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            ans.push_back(u);

            for(auto &v:adj[u])
            {
                inDegree[v]--;
                if(inDegree[v]==0)
                {
                    q.push(v);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //1. first reverse the direction of nodes
        //2. now use topological sort to check which node is come in toplogoical sort 
        //3. return these node (toplogical sort nodes)

        int V=graph.size();
        unordered_map<int,vector<int>>adj;
        vector<int>inDegree(V,0);
        for(int u=0;u<V;u++)
        {
            for(auto &v:graph[u])
            {
                adj[v].push_back(u);
                inDegree[u]++;
            }
        }

        return topologicalSort(adj,inDegree,V);
    }
};
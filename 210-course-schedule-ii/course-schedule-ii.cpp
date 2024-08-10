class Solution {
public:
    vector<int> topologicalSort(unordered_map<int,vector<int>>&adj,vector<int>&inDegree,int n)
    {
        queue<int>q;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(inDegree[i]==0) 
            {
                q.push(i);
                ans.push_back(i);
            }
        }

        while(!q.empty())
        {
            int u=q.front();
            q.pop();

            for(auto &v:adj[u])
            {
                inDegree[v]--;
                if(inDegree[v]==0)
                {
                    q.push(v);
                    ans.push_back(v);
                }
            }
        }
        vector<int>emptyArr;
        int size=ans.size();
        return n==size?ans:emptyArr;

    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        unordered_map<int,vector<int>>adj;
        vector<int>inDegree(n,0);
        for(auto &it:prerequisites)
        {
            int u=it[1];
            int v=it[0];

            adj[u].push_back(v);

            inDegree[v]++;
        }

        return topologicalSort(adj,inDegree,n);
        
    }
};
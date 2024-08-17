class Solution {
public:
    bool topologicalSort(unordered_map<int,vector<int>>&adj, vector<int>&inDegree,int n)
    {
        queue<int>q;
        int course=0;
        for(int i=0;i<n;i++)
        {
            if(inDegree[i]==0)
            {
                q.push(i);
                course++;
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
                    course++;
                    q.push(v);
                }
            }
        }

        return course==n;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
        vector<int>inDegree(numCourses+1,0);
        for(auto &it:prerequisites)
        {
            int v=it[0];  //it[1] --> it[0]
            int u=it[1];
            adj[u].push_back(v);
            inDegree[v]++;
        }

       return  topologicalSort(adj,inDegree,numCourses);
    }

};
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
        vector<int>indegree(numCourses,0);

        for(auto &it:prerequisites)
        {
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
        }

        for(auto &it:adj)
        {
            int v=it.first;
            for(auto &adjNode:it.second)
            {
                indegree[adjNode]++;
            }
        }

        queue<int>q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0) q.push(i);
        }

        vector<int>ans;
        while(!q.empty())
        {
            int u=q.front();
            ans.push_back(u);
            q.pop();

            for(auto &it:adj[u])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                }

            }
        }
       return ans.size()==numCourses; 
    }
};
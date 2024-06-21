class Solution {
public:
    vector<int> topologicalSort(int n, vector<int>&indegree,unordered_map<int,vector<int>>&adj)
    {
        queue<int>q;
        vector<int>ans;
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                ans.push_back(i);
                count++;
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int u=q.front();
            q.pop();

            for(int &v:adj[u])
            {
                indegree[v]--;

                if(indegree[v]==0)
                {
                    ans.push_back(v);
                    count++;
                    q.push(v);
                }
            }
        }

        if(count==n)
            return ans;

        //means we had a cycle and we couldn't complete all courses(visite all nodes )
        return {};
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
        vector<int>indegree(numCourses,0);
        for(auto &vec:prerequisites )
        {
            int a=vec[0];
            int b=vec[1];

            // b-->a 
            adj[b].push_back(a);
            indegree[a]++;
        }

        return topologicalSort(numCourses,indegree,adj);
    }
};
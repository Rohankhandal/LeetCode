class Solution {
public:
    bool checkCycle(int src,unordered_map<int,vector<int>>&adj,vector<bool>&inRec,vector<bool>&visited)
    {
        visited[src]=true;
        inRec[src]=true;

        for(auto &v:adj[src])
        {
            if(!visited[v])
            {
                bool ans=checkCycle(v,adj,inRec,visited);

                if(ans==true) return true;
            }
            else if(inRec[v])
            {
                return true;
            }
        }
        inRec[src]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
        for(auto &it:prerequisites)
        {
            int u=it[1];
            int v=it[0];

            adj[u].push_back(v);
        }
        vector<bool>visited(numCourses,false);
        vector<bool>inRec(numCourses,false);

        int isCycle=false;
        for(int i=0;i<numCourses;i++)
        {
            if(!visited[i])
            {
                isCycle=checkCycle(i,adj,inRec,visited);

                if(isCycle) return false;
            }
           
        }
        return  true;
    }
};
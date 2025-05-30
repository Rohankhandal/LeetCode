class Solution {
public:
    void dfs(vector<int>&edges,vector<int>&dist,int src,vector<bool>&visit)
    {
        visit[src]=true;

        int v=edges[src];

        if(v!=-1 && !visit[v])
        {
             visit[src]=true;
            dist[v]=1+dist[src];
            dfs(edges,dist,v,visit);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int>dist1(n,INT_MAX);
        vector<int>dist2(n,INT_MAX);


        vector<bool>visited1(n,false);
        vector<bool>visited2(n,false);
        dist1[node1]=0;
        dist2[node2]=0;
        dfs(edges,dist1,node1,visited1);
        dfs(edges,dist2,node2,visited2);

        int minDistIndex=-1;
        int minDist=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int maxDis=max(dist1[i],dist2[i]);

            if(minDist>maxDis)
            {
               minDist=maxDis;
               minDistIndex=i;
            }
        }
        return minDistIndex;

    }
};
class Solution
{
    public:
        void checkCycle(int src, vector<int> &edges, vector<int> &count, bool &flag, int &ans, vector< bool > &inRec,vector<bool>&visited)
        {
            int u = src;
            int v = edges[src];
            if(v==-1) return ;
            visited[src] = true;
            inRec[src] = true;


            if (!visited[v])
            {
                count[v] = count[u] + 1;
                checkCycle(v, edges, count, flag, ans, inRec,visited);
            }
            else if (inRec[v])
            {
                ans = count[u] - count[v] + 1;
                flag = true;
            }
            inRec[src]=false;
        }
    int longestCycle(vector<int> &edges)
    {
        int n = edges.size();

        vector<int> count(n, 1);
        vector<bool> inRec(n, false);

        vector<bool> visited(n, false);
        int ans = -1;
        for (int i = 0; i < n; i++)
        {
            bool flag = false;
            int res=0;
            if (!visited[i])
                checkCycle(i, edges, count, flag, res, inRec,visited);

            if (flag) 
            {
                ans=max(ans,res);
            }
        }

        return ans;
    }
};
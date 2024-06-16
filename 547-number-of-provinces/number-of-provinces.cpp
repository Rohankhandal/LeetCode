class Solution {
public:
    void dfs(unordered_map<int,bool>&visited,int src,vector<vector<int>>& isConnected)
    {
        visited[src]=true;
        int size=isConnected.size();
        for(int col=0;col<size;col++ )
        {
            //edge present or not
            if(isConnected[src][col]==1)
            {
                if(!visited[col])
                {
                    dfs(visited,col,isConnected);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int m=isConnected[0].size();
        unordered_map<int,bool>visited;
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(visited,i,isConnected);
                count++;
            }
        }
        return count;
    }
};
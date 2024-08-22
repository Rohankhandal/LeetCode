class Solution {
public:
    //Using BFS
    int bfs(vector<vector<int>>& grid,vector<vector<int>>& visited)
    {
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<int,pair<int,int>>>q;  //{count,{i,j}}
        q.push({0,{0,0}});

        vector<vector<int>>dir{{-1,0},{1,0},{0,1},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}};
        while(!q.empty())
        {
            int count=q.front().first;
            int i=q.front().second.first;
            int j=q.front().second.second;
            q.pop();


            if(i==n-1 && j==m-1)
            {
                return count+1;
            }

            for(auto &d:dir)
            {
                int _i=i+d[0];
                int _j=j+d[1];

                if(_i>=0 && _i<n && _j>=0 && _j<m && grid[_i][_j]==0 && visited[_i][_j]==0)
                {
                    visited[_i][_j]=1;
                    q.push({count+1,{_i,_j}});
                }
            }

        }
        return -1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]==1 || grid[n-1][m-1]==1) return -1;
        vector<vector<int>>visited(n,vector<int>(m,0));

        return bfs(grid,visited);

    }
};
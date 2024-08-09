class Solution {
public:
    void dfs(vector<vector<char>>& grid,int n,int m,int i,int j)
    {
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]!='1')
        {
            return ;
        }

        grid[i][j]='0';

        vector<vector<int>>dir{{-1,0},{1,0},{0,-1},{0,1}};

        for(auto &it:dir)
        {
            int _x=i+it[0];
            int _y=j+it[1];

           
            dfs(grid,n,m,_x,_y);
        }
    }
    void bfs(vector<vector<char>>& grid,int n,int m,int i,int j)
    {
        grid[i][j]='0';

        vector<vector<int>>dir{{-1,0},{1,0},{0,-1},{0,1}};

        queue<pair<int,int>>q;
        q.push({i,j});
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;

            q.pop();

            for(auto &d:dir)
            {
                int _x=x+d[0];
                int _y=y+d[1];
                if(_x<0 || _x >=n || _y<0 || _y>=m || grid[_x][_y]!='1') continue;

                grid[_x][_y]='0';
                q.push({_x,_y});
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    // dfs(grid,n,m,i,j);
                    bfs(grid,n,m,i,j);

                    ans++;
                }
            }
        }
        return ans;
    }
};
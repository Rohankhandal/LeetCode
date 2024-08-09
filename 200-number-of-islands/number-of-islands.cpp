class Solution {
public:
    void solve(vector<vector<char>>& grid,int n,int m,int i,int j)
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

           
            solve(grid,n,m,_x,_y);
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
                    solve(grid,n,m,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
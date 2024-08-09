class Solution {
public:
    bool isSafe(vector<vector<int>>& grid,int i,int j,int n,int m)
    {
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]!=1) return false;

        return true;
    }
    void bfs(vector<vector<int>>& grid,int n,int m,int &ans)
    {
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
            }
        }
        vector<vector<int>>dir{{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty())
        {
            int size=q.size();
            bool foundFresh = false;  // Flag to check if we find fresh oranges
            for(int k=0;k<size;k++)
            {
                int i=q.front().first;
                int j=q.front().second;
                q.pop();

                for(auto &d:dir)
                {
                    int _i=i+d[0];
                    int _j=j+d[1];

                    if(isSafe(grid,_i,_j,n,m))
                    {
                        cout<<_i<<" "<<_j<<endl;
                        grid[_i][_j]=2;
                        q.push({_i,_j});
                        foundFresh=true;
                    }
                }
                cout<<"NEXT"<<endl;
            }
            if(foundFresh)
             ans++;
        }

    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        bfs(grid,n,m,ans);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1) return -1;
            }
        }
        return ans;
    }
};
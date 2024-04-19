class Solution {
public:
int perimeter=0;
    void dfs(vector<vector<int>>& grid,int i,int j,int r, int c)
    {
        if(i>=r || j>=c || i<0 || j<0 || grid[i][j]==0)
        {
            perimeter++;
            return ;
        }
        if(grid[i][j]==-1) return; 

        //marked
        grid[i][j]=-1;

        

        dfs(grid,i+1,j,r,c);
        dfs(grid,i,j+1,r,c);
        dfs(grid,i-1,j,r,c);
        dfs(grid,i,j-1,r,c);
;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==1)
                {
                    dfs(grid,i,j,r,c);
                    return perimeter;
                   
                }
            }
        }
        return 0;
    }
};

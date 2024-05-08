#define ll long long
class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        ll ans=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<int>row(n,0);
        vector<int>col(m,0);
        for(int i=0;i<n;i++)  //row 1's count
        {
            int cnt=0;
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1) cnt++;
            }
            row[i]=cnt;
        }
        for(int j=0;j<m;j++)  //col 1's count
        {
            int cnt=0;
            for(int i=0;i<n;i++)
            {
                if(grid[i][j]==1) cnt++;
            }
            col[j]=cnt;
        }

        //calcualte right traingle
        for(int i=0;i<n;i++) 
        {
            int cnt=0;
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    ans+=(row[i]-1)*(col[j]-1);
                }
            }
        
        }
        return ans;

        

    }
};
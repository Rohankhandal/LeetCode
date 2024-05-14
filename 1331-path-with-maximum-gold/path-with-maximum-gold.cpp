class Solution {
public:
int ans=0;
    vector<vector<int>>dir{{-1,0},{0,1},{0,-1},{1,0}};
    void solve(vector<vector<int>>& grid,int i,int j,int &sum,int n,int m)
    {
        if( i<0 || i>=n || j<0 || j>=m || grid[i][j]==0 )
        {
            return ;
        }
        //store
        int temp=grid[i][j];

        //mark
        grid[i][j]=0;

        sum+=temp;
        
        for(auto &d:dir)
        {
            int i_=i+d[0];
            int j_=j+d[1];
            solve(grid,i_,j_,sum,n,m);
            // cout<<i_ <<" "<<j_<<endl;
            
        }
        ans=max(sum,ans);
        grid[i][j]=temp;
        sum-=temp;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
               int sum=0;
              solve(grid,i,j,sum,n,m);
               
            }
        }
        return ans;
    }
};
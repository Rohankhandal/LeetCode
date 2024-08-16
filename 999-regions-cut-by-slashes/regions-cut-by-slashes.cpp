class Solution {
public:
   vector<vector<int>>dir{{-1,0},{1,0},{0,1},{0,-1}};
    void dfs( vector<vector<int>>&arr,int i,int j)
    {
        int n=arr.size();
        int m=arr[0].size();
        if(i<0 || j<0 || i>=n || j>=m || arr[i][j]==1)
        {
            return ;
        }

        arr[i][j]=1;

        for(auto &d:dir)
        {
            int _i=i+d[0];
            int _j=j+d[1];

            dfs(arr,_i,_j);
        }
        

    }
    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>arr(n*3,vector<int>(m*3,0));

        for(int i=0;i<n;i++)
        {
           for(int j=0;j<m;j++)
           {
            if(grid[i][j]=='/')
            {
                arr[i*3][j*3+2]=1;
                arr[i*3+1][j*3+1]=1;
                arr[i*3+2][j*3]=1;
            }
            else if(grid[i][j]=='\\')
            {
                // i=1,j=0;
                arr[i*3][j*3]=1;
                arr[i*3+1][j*3+1]=1;
                arr[i*3+2][j*3+2]=1;
            }
           }
        }
        

        int ans=0;
        for(int i=0;i<arr.size();i++)
        {
            for(int j=0;j<arr[i].size();j++)
            {
               if(arr[i][j]==0)
               {
                dfs(arr,i,j);
                ans++;
               }
            }
        }

        
        return ans;
    }
};
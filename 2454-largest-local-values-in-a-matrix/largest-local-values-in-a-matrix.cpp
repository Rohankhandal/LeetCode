class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>ans;
        for(int i=0;i<=n-3;i++)
        {
            vector<int>temp;
            for(int j=0;j<=m-3;j++)
            {
                
                int maxi=INT_MIN;
                int a=i,b=j;
                for(a=i;a<3+i;a++)
                {
                    for(b=j;b<3+j;b++)
                    {
                        maxi=max(maxi,grid[a][b]);
                    }
                }
                temp.push_back(maxi);

            }
            ans.push_back(temp);
        }
        return ans;
    }
    
};
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m=grid.size();
        int count=0;
        for(int i=0;i<m;i++)
        {
            int size=grid[i].size();
            int l=0;
            int r=size-1;
            int ans=-1;
            while(l<=r)
            {
                int mid=(l+r)/2;
                if(grid[i][mid]<0)
                {
                    ans=mid;
                    r=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }
            count=count+ (ans!=-1?(size-ans):0);
        }
        return count;
    }
};
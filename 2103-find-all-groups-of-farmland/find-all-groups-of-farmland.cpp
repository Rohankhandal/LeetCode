class Solution {
public:
    vector<vector<int>>directions{{-1,0},{1,0},{0,-1},{0,1}};
    void dfs(vector<vector<int>>& land, int i, int j, int& r2, int& c2) {
        land[i][j] = 0;
        
        r2 = max(r2, i);
        c2 = max(c2, j);
        
        for(auto &dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            
            if(i_ >= 0 && i_ < land.size() && j_ >= 0 && j_ < land[0].size() && land[i_][j_] == 1) {
                dfs(land, i_, j_, r2, c2);
            }
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>>ans;
        int n=land.size();
        int m=land[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(land[i][j]==1)
                {
                    int r1=i;
                    int c1=j;
                    int r2=-1; //these values are maximum values in the rectangle by 1's
                    int c2=-1;
                    dfs(land,i,j,r2,c2);
                    ans.push_back({r1,c1,r2,c2});
                }
            }
        }
        return ans;
    }
};
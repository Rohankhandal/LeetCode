class Solution {
public:
    //Using DijKstra
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]==1 || grid[n-1][m-1]==1) return -1;

        vector<vector<int>>ans(n,vector<int>(m,INT_MAX));

        priority_queue< pair<int,pair<int,int>>,vector< pair<int,pair<int,int>>>,greater< pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        ans[0][0]=0;

        vector<vector<int>>directions{{-1,0},{1,0},{0,1},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}};
        while(!pq.empty())
        {
            int dis=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();

            for(auto &d:directions)
            {
                int newI=i+d[0];
                int newJ=j+d[1];

                 if(newI>=0 && newI<n && newJ>=0 && newJ<m && grid[newI][newJ]==0 )
                {
                    if(dis+1<ans[newI][newJ])
                    {
                        ans[newI][newJ]=dis+1;
                        pq.push({ans[newI][newJ],{newI,newJ}});
                    }
                }
            }
        }
        if(ans[n-1][m-1]==INT_MAX) return -1;

        return ans[n-1][m-1]+1;

    }
};
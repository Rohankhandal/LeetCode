class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n=moveTime.size();
        int m=moveTime[0].size();

        
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        vector<vector<bool>>visit(n,vector<bool>(m,false));
        pq.push({0,0,0,1}); //time,x,y,isAdjacent
        visit[0][0]=true;
        vector<vector<int>>dir{{1,0},{0,1},{0,-1},{-1,0}};

        while(!pq.empty())
        {
            int t=pq.top()[0];
            int x=pq.top()[1];
            int y=pq.top()[2];
            int isAdjacent=pq.top()[3];
            pq.pop();

            if(x==n-1 && y==m-1) return t;

            for(auto &d:dir)
            {
                int i=d[0]+x;
                int j=d[1]+y;

                

                if(i>=0 && j>=0 && i<n && j<m && !visit[i][j])
                {
                    int extraTime=(isAdjacent)?1:2;

                    if(moveTime[i][j]>t)
                    {
                        extraTime+=moveTime[i][j];
                    }
                    else
                    {
                        extraTime+=t;
                    }

                    pq.push({extraTime,i,j,!isAdjacent});
                    visit[i][j]=true;
                }
            }

        }
        return -1;
    }
};
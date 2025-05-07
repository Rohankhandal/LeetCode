class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n=moveTime.size();
        int m=moveTime[0].size();

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;

        pq.push({0,0,0});  //time,i,j
        vector<vector<int>>dir{{-1,0},{1,0},{0,-1},{0,1}};

        moveTime[0][0]=-1;

        while(!pq.empty())
        {
            int t=pq.top()[0];
            int x=pq.top()[1];
            int y=pq.top()[2];
            pq.pop();

            if(x==n-1 && y==m-1) return t;

            for(auto &d:dir)
            {
                int i=d[0]+x;
                int j=d[1]+y;
                if(i>=0 & j>=0 && i<n && j<m && moveTime[i][j]!=-1)
                {
                    int newT=t;
                    if(moveTime[i][j]<=t)
                    {
                        newT++;
                    }
                    else {
                        newT=moveTime[i][j]+1;
                    }
                    
                    moveTime[i][j]=-1;
                    pq.push({newT,i,j});
                }
            }
        }
        return -1;

    }
};
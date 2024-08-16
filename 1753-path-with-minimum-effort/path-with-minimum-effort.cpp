class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();

        vector<vector<int>>distance(n,vector<int>(m,INT_MAX));
        
        priority_queue<P,vector<P>,greater<P>>pq;
        pq.push({0,{0,0}});
        distance[0][0]=0;
        while(!pq.empty())
        {
            int size=pq.size();
            for(int i=0;i<size;i++)
            {
                int d=pq.top().first;
                int x=pq.top().second.first;
                int y=pq.top().second.second;

                pq.pop();
                vector<vector<int>>direction{{-1,0},{1,0},{0,-1},{0,1}};
                for(auto &it:direction)
                {
                    int x_= x + it[0];
                    int y_= y + it[1];
                    if(x_>=0 && y_>=0 && x_<n && y_<m)
                    {
                        int maxDis=max(d,abs(heights[x][y]-heights[x_][y_]));
                        if(distance[x_][y_]>maxDis)
                        {
                            distance[x_][y_]=maxDis;
                            pq.push({distance[x_][y_],{x_,y_}});
                        }
                    }
                    
                }
                
            }
        }
        return distance[n-1][m-1];
    }
};
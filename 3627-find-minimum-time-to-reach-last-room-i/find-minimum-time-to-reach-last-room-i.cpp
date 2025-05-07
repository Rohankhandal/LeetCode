#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> minArrival(n, vector<int>(m, INT_MAX));
        
        // Priority queue holds: {current_time, x, y}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});  // Start at (0, 0) at time 0
        minArrival[0][0] = 0;
        
        vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        
        while (!pq.empty()) {
           int t= pq.top()[0];
            int x= pq.top()[1];
            int y= pq.top()[2]; pq.pop();
            
            if (x == n - 1 && y == m - 1) return t;
            if (t > minArrival[x][y]) continue; // Already found a better way
            
            for (auto& d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                    int wait = moveTime[nx][ny];
                    int nextTime = (t >= wait) ? t + 1 : wait + 1;

                    if (nextTime < minArrival[nx][ny]) {
                        minArrival[nx][ny] = nextTime;
                        pq.push({nextTime, nx, ny});
                    }
                }
            }
        }
        
        return -1; // Should not happen under valid constraints
    }
};

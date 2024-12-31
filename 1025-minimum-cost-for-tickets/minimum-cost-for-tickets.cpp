// //Approach-1 (Recursion + Memoized)  [Time : O(max_day)] [Space : O(n)] //n = size of days vector
// class Solution {
// public:
//     int t[366];
//     int memoized(vector<int>& days, vector<int>& costs, int& n, int idx) {
//         if(idx >= n)
//             return 0; //you can't travel, so no cost
                
//         if(t[idx] != -1)
//             return t[idx];
        
//         //if i take 1-day pass at idx
//         int cost_1 = costs[0] + memoized(days, costs, n, idx+1);
        
        
//         //if i take 7-day pass at idx
//         int i          = idx;
//         while(i < n && days[i] < days[idx]+7) {
//             i++;
//         }
//         int cost_7 = costs[1] + memoized(days, costs, n, i);
        
        
//         //if i take 30-day pass at idx
//         int j      = idx;
//         while(j < n && days[j] < days[idx]+30) {
//             j++;
//         }
//         int cost_30 = costs[2] + memoized(days, costs, n, j);
        
        
//         return t[idx] = min({cost_1, cost_7, cost_30});
//     }
    
//     int mincostTickets(vector<int>& days, vector<int>& costs) {
//         memset(t, -1, sizeof(t));
//         int n = days.size();
//         return memoized(days, costs, n, 0);
//     }
// };
//Approach-3 (Moving from i = n-1 to 0
//Simply replacing recursive calls with t
class Solution {
public:
    
    int solve_bottom_up(vector<int>& days, vector<int>& costs, int n ) {
        
        vector<int> t(n+1, INT_MAX);
        t[n] = 0;
        
        for(int i = n-1; i>=0; i--) {
            
            //1 day pass
            int cost_1 = costs[0] + t[i+1];


            //7 day pass
            int j = i;
            int max_day = days[i] + 7;

            while(j < n && days[j] < max_day) {
                j++;
            }

            int cost_7 = costs[1] + t[j];
            
            
            //30 day pass
            j = i;
            max_day = days[i] + 30;

            while(j < n && days[j] < max_day) {
                j++;
            }

            int cost_30 = costs[2] + t[j] ;

            t[i] = min({cost_1, cost_7, cost_30});
        }
        
        return t[0];
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        
        // memset(t, -1, sizeof(t));
        
        //return solve(days, costs, n, 0);
        
        return solve_bottom_up(days, costs, n);
        
    }
};
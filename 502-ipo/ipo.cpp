class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<vector<int>> x;
        int n=profits.size();
        for(int i=0;i<n;i++){
            x.push_back({capital[i],profits[i]});
        }
        sort(x.begin(),x.end());
        int i=0;
        priority_queue<int> y;
        while(k--){
            while(i<n && x[i][0]<=w){
                y.push(x[i][1]);
                i++;
            }
            if(y.size()==0) break;
            w+=y.top();
            y.pop();
        }
        return w;
    }
};

// class Solution {
// public:
//     int findMaximizedCapital(int k, int paissa, vector<int>& profits, vector<int>& capital) {
//         int n = profits.size();
        
//         // Create a vector of pairs where each pair is (capital, profit)
//         vector<pair<int, int>> vec(n);
//         for (int i = 0; i < n; i++) {
//             vec[i] = {capital[i], profits[i]};
//         }

//         // Sort the projects based on the capital required in ascending order
//         sort(vec.begin(), vec.end());

//         // Use a max-heap (priority queue) to store profits of projects that can be started
//         priority_queue<int> pq;
//         int i = 0;

//         // Greedily pick up to k projects
//         while (k--) {
//             // Add all projects that can be started with the current capital to the max-heap
//             while (i < n && vec[i].first <= paissa) {
//                 pq.push(vec[i].second);
//                 i++;
//             }
//             // If no more projects can be started, break early
//             if (pq.empty())
//                 break;
//             // Select the project with the highest profit
//             paissa += pq.top();
//             pq.pop();
//         }
        
//         return paissa;
//     }
// };

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> jobs;
        for (int i = 0; i < difficulty.size(); ++i) {
            jobs.push_back({difficulty[i], profit[i]});
        }
        
        // Sort jobs by difficulty (ascending order)
        sort(jobs.begin(), jobs.end());
        
        // Sort workers by their ability (ascending order)
        sort(worker.begin(), worker.end());
        
        int maxProfit = 0, bestProfit = 0, j = 0;
        for (int i = 0; i < worker.size(); ++i) {
            // While the current worker can handle the job
            while (j < jobs.size() && worker[i] >= jobs[j].first) {
                bestProfit = max(bestProfit, jobs[j].second);
                ++j;
            }
            maxProfit += bestProfit;
        }
        
        return maxProfit;
    }
};

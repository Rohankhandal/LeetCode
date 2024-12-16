class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n=nums.size();
        vector<int>ans(n,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }

        while(k>0)
        {
            int ele=pq.top().first;
            int idx=pq.top().second;

            ele*=multiplier;

            pq.pop();
            pq.push({ele,idx});

            k--;
        }

        while(!pq.empty())
        {
            int ele=pq.top().first;
            int idx=pq.top().second;

            ans[idx]=ele;
            pq.pop();
        }
        return ans;
    }
};
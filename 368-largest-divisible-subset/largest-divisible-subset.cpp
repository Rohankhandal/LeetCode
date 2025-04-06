class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>dp(n,1);
        vector<int>parent(n,1);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        int maxLen=1;
        int maxIdx=0;
         for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                maxIdx = i;
            }
        }
        vector<int>ans;
        
        int val=maxIdx;
        while(val!=parent[val])
        {
            ans.push_back(nums[val]);
            val=parent[val];
        }
        ans.push_back(nums[val]);
       reverse(ans.begin(),ans.end());
        return ans;
    }
};
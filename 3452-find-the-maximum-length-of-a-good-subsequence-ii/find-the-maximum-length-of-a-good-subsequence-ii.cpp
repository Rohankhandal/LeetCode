class Solution {
public:
    int dp[5001][51][2];
    int f(vector<int>& nums, int i, int k, int flag,unordered_map<int, vector<int>>& mp) {
        if (i == nums.size())
            return 0;
        if (dp[i][k][flag] != -1)
            return dp[i][k][flag];

        // take
        auto& temp = mp[nums[i]];
        int idx = upper_bound(temp.begin(), temp.end(), i) - temp.begin();

        int take = 0;
        if(idx==temp.size()) take=1;
        else 
        take = 1 + f(nums,temp[idx], k, 1, mp);

        if (k > 0) take=max(take,1+f(nums,i+1,k-1,0,mp));


        //skip
        int skip=0;
        if(flag==0) skip=f(nums,i+1,k,0,mp);
        
        
        return dp[i][k][flag]=max(take,skip);
    }
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {

            mp[nums[i]].push_back(i);
        }
        memset(dp, -1, sizeof(dp));
        return f(nums, 0, k ,0, mp); // 0=> means not same , 1=> same
    }
};
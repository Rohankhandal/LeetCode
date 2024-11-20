class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans(n-k+1,-1);

        int consecutiveCnt=1;
        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1]+1)
            {
                consecutiveCnt++;
            }
            else
            {
                consecutiveCnt=1;
            }

            if(consecutiveCnt>=k) ans[i-k+1]=nums[i];
        }

        return ans;
    }
};
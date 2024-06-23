class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int flip=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if((flip+nums[i])%2==0)
            {
                flip++;
                ans++;
                
            }
        }
        return ans;
    }
};
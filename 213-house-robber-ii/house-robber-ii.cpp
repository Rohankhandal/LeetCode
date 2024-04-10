class Solution {
public:
    int space(vector<int>&nums)
    {
        int n=nums.size();
        int prev2=0;
        int prev1=nums[n-1];
        int curr=0;
        for(int i=n-2;i>=0;i--)
        {
            int include=nums[i];
            if(i+2<=n)
            {
                include+=prev2;
            }    
            int exclude=0+prev1;

            curr=max(include,exclude);

            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int>first(n-1);
        vector<int>last(n-1);
        for(int i=0;i<n-1;i++)
        {
            first[i]=nums[i];
        }
        for(int i=1;i<n;i++)
        {
            last[i-1]=nums[i];
        }
        return max(space(first),space(last));
    }
};
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int eSum=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            eSum+=nums[i];

        }
        for(int i=0;i<=nums.size();i++)
        {
            sum+=i;
        }
        int ans=sum-eSum;
        return ans;
    }
};
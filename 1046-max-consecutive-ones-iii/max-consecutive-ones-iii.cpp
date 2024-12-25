class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int zero=0;
        int i=0,j=0;
        int ans=0;
        while(j<n)
        {
            if(nums[j]==0) k--;
            while(k<0 && i<=j)
            {
                if(nums[i]==0) k++;
                i++;
            }
            ans=max(j-i+1,ans);
            j++;
        }
        return ans;
    }
};
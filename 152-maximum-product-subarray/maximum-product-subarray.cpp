class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int prefix=1,suffix=1;
        int ans=INT_MIN;
        while(i<n)
        {
            if(prefix==0) prefix=1;
            if(suffix==0) suffix=1;

            prefix*=nums[i];
            suffix*=nums[n-i-1];
            ans=max({ans,prefix,suffix});
            i++;
        }
        return ans;
    }
};
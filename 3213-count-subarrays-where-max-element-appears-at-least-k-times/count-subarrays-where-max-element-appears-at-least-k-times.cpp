class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans=0;
        int maxEle=*max_element(nums.begin(),nums.end());
        
        int l=0,r=0;
        int n=nums.size();

        int freqMax=0;
        while(r<n){
            if(nums[r]==maxEle) freqMax++;

            while(l<=r && freqMax>=k)
            {
                ans+=(n-r);
                if(nums[l]==maxEle) freqMax--;
                l++;
            }

            r++;
        }
        return ans;
        
    }
};
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        long long sum=0,maxi=0;

        unordered_map<int,int>check;
        for(int i=0;i<k-1;i++)
        {
            sum+=nums[i];   //process k-1 elements
            check[nums[i]]++;
        }

        for(int i=k-1;i<n;i++)
        {
            check[nums[i]]++;
            sum+=nums[i];
            if(check.size()==k)
            {
                maxi=max(maxi,sum);
            }
            if(check[nums[i-k+1]]==1)  //remove character out of window k.
            {
                check.erase(nums[i-k+1]);   //if frequency is one then remove from map bcz that element is contribute in size ,if we decrement the frequnecy
            }
            else
            {
                check[nums[i-k+1]]--;
            }
            sum-=nums[i-k+1];
        }
        return maxi;
    }
};
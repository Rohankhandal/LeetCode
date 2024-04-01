class Solution {
public:
    int binarySearch(int target_idx,vector<int>&nums,vector<long long>&prefixSum,int k)
    {
        int target=nums[target_idx];
        int i=0;
        int j=target_idx;
        int result = target_idx;
        
        while(i <= j) {
            int mid = i + (j-i)/2;
            
            long count      = (target_idx - mid + 1);
            long windowSum  = (count * target);
            long currSum    = prefixSum[target_idx] - prefixSum[mid] + nums[mid];  //DRY RUN 
            
            int ops         = windowSum - currSum;
            
            if(ops > k ) {
                i = mid+1;
            } else {
                result = mid;//posssible find largest window,that's why store the answer
                j = mid-1;    
            }
        }
        
        return target_idx-result+1;
    }
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());   //bcz a number is only ask for increase which is less than the 
    //current index value
        int n=nums.size();
        vector<long long>prefix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            prefix[i]=nums[i]+prefix[i-1];
        }  
        int result=0;
        for(int target_idx=0;target_idx<n;target_idx++)
        {
            result=max(result,binarySearch(target_idx,nums,prefix,k));
        }
        return result;
    }
};
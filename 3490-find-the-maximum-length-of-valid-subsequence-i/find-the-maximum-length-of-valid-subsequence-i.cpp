class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            nums[i]=nums[i]%2;
        }

        int ans=0;
        int len=0;
        //all even
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0) len++;
        }
        ans=max(ans,len);

        //all odd
        len=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1) len++;
        }
        ans=max(ans,len);

        //all even-odd
        bool even=true;
        len=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0 && even)
            {
                even=false;
                len++;
            }
            else if(nums[i]==1 && !even) 
            {
                even=true;
                len++;
            }
        }
        ans=max(ans,len);

        //all odd-even
        bool odd=true;
        len=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1 && odd)
            {
                odd=false;
                len++;
            }
            else if(nums[i]==0 && !odd) 
            {
                odd=true;
                len++;
            }

        }
        ans=max(ans,len);

        return ans;
    }
};
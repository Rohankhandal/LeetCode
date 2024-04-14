class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        vector<bool>prime(101,false);
        for(int i=2;i<101;i++)
        {
            bool flag=false;
            for(int j=2;j<=i-1;j++)
            {
                if(i%j==0)
                {
                    flag=true;
                    break;
                }
            }
            if(!flag)
            {
                prime[i]=true;
            }
        }
        int ans=INT_MIN;
        int l=0,r=nums.size()-1;
        while(l<=r)
        {
            if(prime[nums[l]] && prime[nums[r]])
            {
                ans=max(ans,r-l);
                break;
            }
            else if(prime[nums[l]])
            {
                r--;
            }
            else if(prime[nums[r]])
            {
                l++;
            }
            else
            {
                l++;
                r--;
            }
        }
        return ans;
    }
};
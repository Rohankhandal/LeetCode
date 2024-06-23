class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n-2;i++)
        {
            if(nums[i]==0)
            {
                for(int j=i;j<i+3;j++)
                {
                    nums[j]=(nums[j]+1)%2;
                    // cout<<j<<" "<<nums[j]<<endl;
                }
                ans++;
            }
           
        }
        bool flag=true;
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=1)
            {
                flag=false;
                break;
            }
        }
        if(!flag) return -1;
        return ans;
    }
};
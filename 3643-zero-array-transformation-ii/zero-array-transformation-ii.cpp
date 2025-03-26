class Solution {
public:
    bool isPossible(vector<int> nums, vector<vector<int>>& queries,int limit)
    {
        int n=nums.size();
        vector<int>v(n+2,0);
        for(int i=0;i<limit;i++)
        {
            int l=queries[i][0];
            int r=queries[i][1];
            int val=queries[i][2];
            v[l]+=val;
            v[r+1]-=val;
        }

        for(int i=1;i<n;i++)
        {
            v[i]+=v[i-1];
        }

        for(int i=0;i<n;i++){
            if(v[i]>=nums[i])
            {
                nums[i]=0;
            }
            if(nums[i]!=0) return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int l=0,r=queries.size();
        int ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(isPossible(nums,queries,mid))
            {
                ans=mid;
                r=mid-1;
            }
            else {
                l=mid+1;
            }
        }
        return ans;
    }
};
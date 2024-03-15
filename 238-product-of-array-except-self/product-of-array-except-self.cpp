class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,0);
        int prod=1;
        vector<int>prefix(n,0);
        vector<int>suffix(n,0);
        prefix[0]=1;
        prefix[1]=nums[0];
        suffix[n-1]=1;
        suffix[n-2]=nums[n-1];
        for(int i=2;i<n;i++)
        {
            prefix[i]=prefix[i-1]*nums[i-1];
        }
        for(int i=n-3;i>=0;i--)
        {
            suffix[i]=suffix[i+1]*nums[i+1];
        }
        for(auto &it:prefix )
        {
            cout<<it<<" ";
        }
        cout<<endl;
        for(auto &it:suffix )
        {
            cout<<it<<" ";
        }
        cout<<endl;
        
        for(int i=0;i<n;i++)
        {
              ans[i]=prefix[i]*suffix[i];
        }
        return ans;


    }
};
class Solution {
public:
    int pivotInteger(int n) {
        if(n==1) return 1;
        vector<int>prefix(n,0);
        vector<int>suffix(n,0);
        int ans=-1;
        //prefix sum
        prefix[0]=1;
        for(int i=1;i<n;i++)
        {
            prefix[i]=i+1+prefix[i-1];
        }
        //suffix sum
        suffix[n-1]=n;
        for(int i=n-2;i>=0;i--)
        {
            suffix[i]=i+1+suffix[i+1];
        }
        // //prefix
        // for(auto &it:prefix)
        // {
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        // for(auto &it:suffix)
        // {
        //     cout<<it<<" ";
        // }
        for(int i=0;i<n;i++)
        {
            if(prefix[i]==suffix[i])
                return prefix[i]-prefix[i-1];
        }
        return ans;

    }
};